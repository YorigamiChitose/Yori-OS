#ifndef __OUTPUT_H__
#define __OUTPUT_H__

#include <common/printf.h>
#include <sbi/sbi.h>

#define LOG_LEVEL_TRACE

#if defined(LOG_LEVEL_ERROR)

#define USE_LOG_ERROR

#endif // LOG_LEVEL_ERROR

#if defined(LOG_LEVEL_WARN)

#define USE_LOG_ERROR
#define USE_LOG_WARN

#endif // LOG_LEVEL_ERROR

#if defined(LOG_LEVEL_INFO)

#define USE_LOG_ERROR
#define USE_LOG_WARN
#define USE_LOG_INFO

#endif // LOG_LEVEL_INFO

#if defined(LOG_LEVEL_DEBUG)

#define USE_LOG_ERROR
#define USE_LOG_WARN
#define USE_LOG_INFO
#define USE_LOG_DEBUG

#endif // LOG_LEVEL_DEBUG

#if defined(LOG_LEVEL_TRACE)

#define USE_LOG_ERROR
#define USE_LOG_WARN
#define USE_LOG_INFO
#define USE_LOG_DEBUG
#define USE_LOG_TRACE

#endif // LOG_LEVEL_TRACE

enum LOG_COLOR {
	RED = 31,
	GREEN = 32,
	BLUE = 34,
	GRAY = 90,
	YELLOW = 93,
};


#if defined(USE_LOG_ERROR)
#define errorf(fmt, ...)                                     \
	do {                                                     \
		printf("\x1b[%dm[%s] " fmt "\x1b[0m\n", RED, "ERROR", \
		       ##__VA_ARGS__);                               \
	} while (0)
#else
#define errorf(fmt, ...)
#endif // USE_LOG_ERROR

#if defined(USE_LOG_WARN)
#define warnf(fmt, ...)                                        \
	do {                                                       \
		printf("\x1b[%dm[%s] " fmt "\x1b[0m\n", YELLOW, " WARN", \
		       ##__VA_ARGS__);                                 \
	} while (0)
#else
#define warnf(fmt, ...)
#endif // USE_LOG_WARN

#if defined(USE_LOG_INFO)
#define infof(fmt, ...)                                      \
	do {                                                     \
		printf("\x1b[%dm[%s] " fmt "\x1b[0m\n", BLUE, " INFO", \
		       ##__VA_ARGS__);                               \
	} while (0)
#else
#define infof(fmt, ...)
#endif // USE_LOG_INFO

#if defined(USE_LOG_DEBUG)
#define debugf(fmt, ...)                                       \
	do {                                                       \
		printf("\x1b[%dm[%s] " fmt "\x1b[0m\n", GREEN, "DEBUG", \
		       ##__VA_ARGS__);                                 \
	} while (0)
#else
#define debugf(fmt, ...)
#endif // USE_LOG_DEBUG

#if defined(USE_LOG_TRACE)
#define tracef(fmt, ...)                                      \
	do {                                                      \
		printf("\x1b[%dm[%s] " fmt "\x1b[0m\n", GRAY, "TRACE", \
		       ##__VA_ARGS__);                                \
	} while (0)
#else
#define tracef(fmt, ...)
#endif // USE_LOG_TRACE

#define panic(fmt, ...)                                     \
	do {                                                    \
		printf("\x1b[%dm[%s] %s:%d: " fmt "\x1b[0m\n", RED, \
		       "PANIC", __FILE__, __LINE__, ##__VA_ARGS__); \
		shutdown();                                         \
	} while (0)


#endif