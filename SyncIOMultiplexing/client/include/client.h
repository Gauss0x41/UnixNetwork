#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <poll.h>
#include <pthread.h> 

#include "log.h"

#define IP_ADDR_SIZE 16
#define PACKED __attribute__((__packed__))

typdef struct _linked_list_t{
  size_t data_length;
  void *data;
  struct linked_list_t *next_node = NULL;
};

typedef struct _connection_t{
  int socket_fd;
  int timeout;
  uint32_t port;
  char ip_addr[IP_ADDR_SIZE];
  struct pollfd poll_fd; // poll fd to listen for incoming data or when the file descriptor can be be written to 
}connection_t;

typedef struct _outgoing_message_t{
  uint8_t message_type;
  size_t message_size;
  void *outgoing_message;
} PACKED outgoing_message_t;

typedef struct _incoming_message_t{
  uint8_t message_type;
  size_t message_size;
  void *incoming_message;
} PACKED incoming_message_t;

void linked_list_insert_at_end(void *data, size_t data_length);

bool client_write_to_server(void *outgoing_message, connection_t *connection);

incoming_message_t *client_read_from_server(void *incoming_message, connection_t *connection);

bool client_poll_worker_thread(connection_t *connection);


#endif // CLIENT_H
