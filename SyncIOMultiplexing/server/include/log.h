#ifndef DEBUG_H
#define DEBUG_H

#ifdef DEBUG

#define LOG_PRINT(fmt, ...) \
  do{ fprintf(stderr, "%s:%d:%s():  " fmt, __FILE__, \
	      __LINE__, __func__, ##__VA_ARGS__); fflush(stderr);} while(0)

#endif // DEBUG

#endif // DEBUG_H
