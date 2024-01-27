#ifndef _STATIC_STRING_H_
#define _STATIC_STRING_H_

#include <inttypes.h>
#include <stdio.h>

#define SSTR8  0x00
#define SSTR16 0x01
#define SSTR32 0x02
#define SSTR64 0x03

/*
 * sstr_reset resets static string to be empty.
 */
#define sstr_reset(s) do { \
	s->_buf[0] = 0;    \
	s->_str._len = 0;  \
} while(0)

#define sstr_print(str) do {            \
	if (str._str._len > 0)          \
		printf("%s", str._buf); \
} while (0)

#define sstr_println(str) do {            \
	if (str._str._len > 0)            \
		printf("%s\n", str._buf); \
	else                              \
		printf("\n");             \
} while (0)

typedef struct {
	uint16_t _len;
	uint8_t  _type;
} sstr_t;

typedef struct {
	sstr_t _str;
	char _buf[8];
} sstr8_t;

#define sstr8_init(name, str) sstr8_t name = {{._len = sizeof(str) - 1, ._type = SSTR8}, ._buf = str}

/*
 * sstr_len returns string current length. The null byte ('\0') is not included
 * in the string length. Getting string length has O(1) complexity.
 * The macro works for string values as well as for string pointers.
 */
#define sstr_len(s) _Generic((s), \
	sstr8_t  : _sstr_len,     \
	sstr8_t* : _sstr_ptr_len  \
) (s)

static inline __attribute__((always_inline))
uint8_t _sstr_len(sstr8_t s) {
	return s._str._len;
}

static inline __attribute__((always_inline))
uint8_t _sstr_ptr_len(sstr8_t *s) {
	return s->_str._len;
}

#define sstr_write_char(s, x) _Generic((s), \
	sstr8_t*: sstr8_write_char          \
)(s, x)

void sstr8_write_char(sstr8_t *s, char x);

#define sstr_write(s, x) _Generic((s),  \
	sstr8_t*: sstr8_uint8_write     \
)(s, x)

#define sstr8_write(s, x) _Generic((x), \
	uint8_t: sstr8_uint8_write      \
)(s, x)

void sstr8_uint8_write(sstr8_t *s, uint8_t x);

#endif // _STATIC_STRING_H_
