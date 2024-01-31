// SPDX-License-Identifier: MIT
// https://github.com/m-kru/c-sstr
// Copyright (c) 2024 Michał Kruszewski

#ifndef _SSTR_H_
#define _SSTR_H_

#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>

#define SSTR8    0x00
#define SSTR16   0x01
#define SSTR32   0x02
#define SSTR64   0x03
#define SSTR128  0x04
#define SSTR256  0x05
#define SSTR512  0x06
#define SSTR1024 0x07
#define SSTR2048 0x08
#define SSTR4096 0x09
#define SSTR8192 0x0A

typedef struct {
	uint16_t _len;
	uint8_t  _type;
} sstr_t;

#if !defined SSTR_NO_SPACE_CB && defined SSTR_DEFAULT_CB
	#error "SSTR_DEFAULT_CB requires SSTR_NO_SPACE_CB to be defined as well"
#endif
#if !defined SSTR_DEFAULT_CB && defined SSTR_CB_STREAM
	#error "SSTR_CB_STREAM requires SSTR_DEFAULT_CB to be defined as well"
#endif
#if defined SSTR_DEFAULT_CB && !defined SSTR_CB_STREAM
	#define SSTR_CB_STREAM stderr
#endif

#ifdef SSTR_NO_SPACE_CB
void sstr_no_space_cb(
	const char * fn_name,
	const sstr_t * str,
	const char * arg
);
#endif

/*
 * sstr_reset resets static string to be empty.
 */
#define sstr_reset(s) do {  \
	(s)->_buf[0] = 0;   \
	(s)->_str._len = 0; \
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

/*
 * p is the precision specifier. 
 */
#define sstr_write_float(s, x, p) _Generic((s), \
	sstr8_t*: sstr8_write_float             \
)(s, x, p)

void sstr8_write_float(sstr8_t *s, float x, uint8_t p);

/*
 * p is the precision specifier. 
 */
#define sstr_write_double(s, x, p) _Generic((s), \
	sstr8_t*: sstr8_write_double             \
)(s, x, p)

void sstr8_write_double(sstr8_t *s, double x, uint8_t p);

#define sstr_write(s, x) _Generic((s),         \
	sstr8_t*: _Generic((x),                \
		bool     : sstr8_write_bool,   \
		char*    : sstr8_write_string, \
		uint8_t  : sstr8_write_u8,     \
		uint16_t : sstr8_write_u16,    \
		uint32_t : sstr8_write_u32,    \
		uint64_t : sstr8_write_u64,    \
		int8_t   : sstr8_write_i8,     \
		int16_t  : sstr8_write_i16,    \
		int32_t  : sstr8_write_i32,    \
		int64_t  : sstr8_write_i64)    \
)(s, x)

void sstr8_write_bool(sstr8_t *s, bool x);
void sstr8_write_string(sstr8_t *s, char *x);
void sstr8_write_u8(sstr8_t *s, uint8_t x);
void sstr8_write_u16(sstr8_t *s, uint16_t x);
void sstr8_write_u32(sstr8_t *s, uint32_t x);
void sstr8_write_u64(sstr8_t *s, uint64_t x);
void sstr8_write_i8(sstr8_t *s, int8_t x);
void sstr8_write_i16(sstr8_t *s, int16_t x);
void sstr8_write_i32(sstr8_t *s, int32_t x);
void sstr8_write_i64(sstr8_t *s, int64_t x);

/*
 * fw controls whether value shall have fixed width.
 */
#define sstr_write_hex(s, x, fw) _Generic((s),  \
	sstr8_t*: _Generic((x),                 \
		uint8_t  : sstr8_write_hex_u8,  \
		uint16_t : sstr8_write_hex_u16, \
		uint32_t : sstr8_write_hex_u32, \
		uint64_t : sstr8_write_hex_u64) \
)(s, x, fw)

#define write_hex_declarations(CAP) \
	void sstr ## CAP ##_write_hex_u8 (sstr ## CAP ## _t *s, uint8_t x, bool fw);  \
	void sstr ## CAP ##_write_hex_u16(sstr ## CAP ## _t *s, uint16_t x, bool fw); \
	void sstr ## CAP ##_write_hex_u32(sstr ## CAP ## _t *s, uint32_t x, bool fw); \
	void sstr ## CAP ##_write_hex_u64(sstr ## CAP ## _t *s, uint64_t x, bool fw)

write_hex_declarations(8);

#endif // _SSTR_H_
