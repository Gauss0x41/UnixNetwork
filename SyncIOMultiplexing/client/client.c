#include "client.h"
#include "log.h"

#define POLL_CHECK(poll_re_event, check_val) (poll_re_event & check_val)

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

void *
client_get_poll(void *thread_argument){

}

bool
client_poll_worker_thread(connection_t *connection){
  bool kill_poll_thread = true;
  pthread_t thread_id;


  return kill_poll_thread;

}
