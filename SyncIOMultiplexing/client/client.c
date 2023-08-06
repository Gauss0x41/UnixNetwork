#include "client.h"
#include "log.h"

#define NUM_SOCKETS 1

#define POLL_CHECK(poll_re_event, check_val) (poll_re_event & check_val)

linked_list_t *
linked_list_init(void){
  linked_list_t *linked_list = NULL;

  linked_list = malloc(sizeof(linked_list_t));
  if(linked_list == NULL){
    LOG_PRINT("Failed to initialized linked list structure");
  }
  return linked_list;
}

void
linked_list_insert_at_end(linked_list_t *linked_list, void *data, size_t *data_length){
 
}

bool
client_write_to_server(void *outgoing_message, connection_t *connection){
  bool wrote_all_data = true;
  size_t data_written = 0;
  // Write result to server
  
  return wrote_all_data;
}

incoming_message_t *
client_read_from_server(void *incoming_message, connection_t *connection){
  bool read_all_data = true;
  size_t data_read = 0;
  // read data from server

  return read_all_data;
}

static void *
client_get_poll(void *thread_argument){
  int poll_return;
  short event;
  connection_t *connection = NULL;
  struct pollfd *poll_fd = NULL;

  connection = (connection_t *)thread_argument;
  poll_fd = ((connection_t *)thread_argument)->poll_fd;
  do{
    // Check for event
    poll_return = poll(poll_fd->fd, NUM_SOCKETS, connection->timeout);
    if(POLL_CHECK(poll_fd->revents, POLLIN) == POLLIN){
      LOG_PRINT("Socket descriptor is ready for reading");
      // do read
      
      continue;
    }
    if(POLL_CHECK(poll_fd->revents, POLLOUT) == POLLOUT){
      LOG_PRINT("Socket descriptor is ready for writing");
      // do write
      
      continue;
    }
  }while(poll_return > 0);

  LOG_PRINT("Leaving client get poll");
}

bool
client_poll_worker_thread(connection_t *connection){
  bool kill_poll_thread = true;
  pthread_t thread_id;


  return kill_poll_thread;

}
