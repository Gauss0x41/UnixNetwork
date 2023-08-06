#include "client.h"

connection_t connection = {
  .port = 11111,
  .timeout = 25000,
  .ip_addr = "127.0.0.1",
  .poll_fd.events = POLLIN | POLLOUT;
};

int main(void){
  /* 
     Client needs to be able to listen on a socket file desc and be able to read data coming in the from
     the server, do some work, while also doing other functions and using the file descripor to write data
     to the server.
  */
  int client_ret;
  struct sockaddr_in serv_addr;
  
  LOG_PRINT("In client main.");

  connection.socket_fd = socket(AF_INET, SOCK_STREAM, SOCK_NONBLOCK); // Socket is non blocking 
  if(connection == -1){
    LOG_PRINT("Failed to get a file descriptor");
    client = -1;
    goto exit;
  }

  connection.poll_fd.fd = connection.socket_fd;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(connection.port);
  serv_addr.sin_addr = connection.ip_addr;



  
    
 exit:
  
  LOG_PRINT("Client is exiting");
  
  return 0;
}
