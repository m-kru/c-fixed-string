// SPDX-License-Identifier: MIT
// https://github.com/m-kru/c-fstr
// Copyright (c) 2024 Michał Kruszewski

#ifndef _FSTR_H_
#define _FSTR_H_

#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>

#define FSTR8    0x00
#define FSTR16   0x01
#define FSTR32   0x02
#define FSTR64   0x03
#define FSTR128  0x04
#define FSTR256  0x05
#define FSTR512  0x06
#define FSTR1024 0x07
#define FSTR2048 0x08
#define FSTR4096 0x09
#define FSTR8192 0x0A

typedef struct {
	uint16_t _len;
	uint8_t  _type;
} fstr_t;

#if !defined FSTR_NO_SPACE_CB && defined FSTR_DEFAULT_CB
	#error "FSTR_DEFAULT_CB requires FSTR_NO_SPACE_CB to be defined as well"
#endif
#if !defined FSTR_DEFAULT_CB && defined FSTR_CB_STREAM
	#error "FSTR_CB_STREAM requires FSTR_DEFAULT_CB to be defined as well"
#endif
#if defined FSTR_DEFAULT_CB && !defined FSTR_CB_STREAM
	#define FSTR_CB_STREAM stderr
#endif

#ifdef FSTR_NO_SPACE_CB
void fstr_no_space_cb(
	const char * fn_name,
	const fstr_t * str,
	const char * arg
);
#endif

/*
 * fstr_reset resets static string to be empty.
 */
#define fstr_reset(s) do {  \
	(s)->_buf[0] = 0;   \
	(s)->_str._len = 0; \
} while(0)

#define fstr_print(str) do {            \
	if (str._str._len > 0)          \
		printf("%s", str._buf); \
} while (0)

#define fstr_println(str) do {            \
	if (str._str._len > 0)            \
		printf("%s\n", str._buf); \
	else                              \
		printf("\n");             \
} while (0)

typedef struct {
	fstr_t _str;
	char _buf[8];
} fstr8_t;

#define fstr8_init(name, str) fstr8_t name = {{._len = sizeof(str) - 1, ._type = FSTR8}, ._buf = str}

/*
 * fstr_len returns string current length. The null byte ('\0') is not included
 * in the string length. Getting string length has O(1) complexity.
 * The macro works for string values as well as for string pointers.
 */
#define fstr_len(s) _Generic((s), \
	fstr8_t  : _fstr_len,     \
	fstr8_t* : _fstr_ptr_len  \
) (s)

static inline __attribute__((always_inline))
uint8_t _fstr_len(fstr8_t s) {
	return s._str._len;
}

static inline __attribute__((always_inline))
uint8_t _fstr_ptr_len(fstr8_t *s) {
	return s->_str._len;
}

#define fstr_write_char(s, x) _Generic((s), \
	fstr8_t*: fstr8_write_char          \
)(s, x)

/*
 * p is the precision specifier. 
 */
#define fstr_write_float(s, x, p) _Generic((s), \
	fstr8_t*: fstr8_write_float             \
)(s, x, p)

/*
 * p is the precision specifier. 
 */
#define fstr_write_double(s, x, p) _Generic((s), \
	fstr8_t*: fstr8_write_double             \
)(s, x, p)

#define fstr_write(s, x) _Generic((s),         \
	fstr8_t*: _Generic((x),                \
		bool     : fstr8_write_bool,   \
		char*    : fstr8_write_string, \
		uint8_t  : fstr8_write_u8,     \
		uint16_t : fstr8_write_u16,    \
		uint32_t : fstr8_write_u32,    \
		uint64_t : fstr8_write_u64,    \
		int8_t   : fstr8_write_i8,     \
		int16_t  : fstr8_write_i16,    \
		int32_t  : fstr8_write_i32,    \
		int64_t  : fstr8_write_i64)    \
)(s, x)

/*
 * fw controls whether value shall have fixed width.
 */
#define fstr_write_hex(s, x, fw) _Generic((s),  \
	fstr8_t*: _Generic((x),                 \
		uint8_t  : fstr8_write_hex_u8,  \
		uint16_t : fstr8_write_hex_u16, \
		uint32_t : fstr8_write_hex_u32, \
		uint64_t : fstr8_write_hex_u64) \
)(s, x, fw)

/*
 * fw controls whether value shall have fixed width.
 */
#define fstr_write_xhex(s, x, fw) _Generic((s),  \
	fstr8_t*: _Generic((x),                  \
		uint8_t  : fstr8_write_xhex_u8,  \
		uint16_t : fstr8_write_xhex_u16, \
		uint32_t : fstr8_write_xhex_u32, \
		uint64_t : fstr8_write_xhex_u64) \
)(s, x, fw)

/*
 * fw controls whether value shall have fixed width.
 */
#define fstr_write_HEX(s, x, fw) _Generic((s),  \
	fstr8_t*: _Generic((x),                 \
		uint8_t  : fstr8_write_HEX_u8,  \
		uint16_t : fstr8_write_HEX_u16, \
		uint32_t : fstr8_write_HEX_u32, \
		uint64_t : fstr8_write_HEX_u64) \
)(s, x, fw)

/*
 * fw controls whether value shall have fixed width.
 */
#define fstr_write_xHEX(s, x, fw) _Generic((s),  \
	fstr8_t*: _Generic((x),                  \
		uint8_t  : fstr8_write_xHEX_u8,  \
		uint16_t : fstr8_write_xHEX_u16, \
		uint32_t : fstr8_write_xHEX_u32, \
		uint64_t : fstr8_write_xHEX_u64) \
)(s, x, fw)

#define _fstr_function_declarations(N) \
void fstr ## N ## _write_char     (fstr ## N ##_t *s, char     x);            \
void fstr ## N ## _write_bool     (fstr ## N ##_t *s, bool     x);            \
void fstr ## N ## _write_string   (fstr ## N ##_t *s, char    *x);            \
void fstr ## N ## _write_u8       (fstr ## N ##_t *s, uint8_t  x);            \
void fstr ## N ## _write_u16      (fstr ## N ##_t *s, uint16_t x);            \
void fstr ## N ## _write_u32      (fstr ## N ##_t *s, uint32_t x);            \
void fstr ## N ## _write_u64      (fstr ## N ##_t *s, uint64_t x);            \
void fstr ## N ## _write_i8       (fstr ## N ##_t *s, int8_t   x);            \
void fstr ## N ## _write_i16      (fstr ## N ##_t *s, int16_t  x);            \
void fstr ## N ## _write_i32      (fstr ## N ##_t *s, int32_t  x);            \
void fstr ## N ## _write_i64      (fstr ## N ##_t *s, int64_t  x);            \
void fstr ## N ## _write_float    (fstr ## N ##_t *s, float    x, uint8_t p); \
void fstr ## N ## _write_double   (fstr ## N ##_t *s, double   x, uint8_t p); \
void fstr ## N ## _write_hex_u8   (fstr ## N ##_t *s, uint8_t  x, bool fw);   \
void fstr ## N ## _write_hex_u16  (fstr ## N ##_t *s, uint16_t x, bool fw);   \
void fstr ## N ## _write_hex_u32  (fstr ## N ##_t *s, uint32_t x, bool fw);   \
void fstr ## N ## _write_hex_u64  (fstr ## N ##_t *s, uint64_t x, bool fw);   \
void fstr ## N ## _write_xhex_u8  (fstr ## N ##_t *s, uint8_t  x, bool fw);   \
void fstr ## N ## _write_xhex_u16 (fstr ## N ##_t *s, uint16_t x, bool fw);   \
void fstr ## N ## _write_xhex_u32 (fstr ## N ##_t *s, uint32_t x, bool fw);   \
void fstr ## N ## _write_xhex_u64 (fstr ## N ##_t *s, uint64_t x, bool fw);   \
void fstr ## N ## _write_HEX_u8   (fstr ## N ##_t *s, uint8_t  x, bool fw);   \
void fstr ## N ## _write_HEX_u16  (fstr ## N ##_t *s, uint16_t x, bool fw);   \
void fstr ## N ## _write_HEX_u32  (fstr ## N ##_t *s, uint32_t x, bool fw);   \
void fstr ## N ## _write_HEX_u64  (fstr ## N ##_t *s, uint64_t x, bool fw);   \
void fstr ## N ## _write_xHEX_u8  (fstr ## N ##_t *s, uint8_t  x, bool fw);   \
void fstr ## N ## _write_xHEX_u16 (fstr ## N ##_t *s, uint16_t x, bool fw);   \
void fstr ## N ## _write_xHEX_u32 (fstr ## N ##_t *s, uint32_t x, bool fw);   \
void fstr ## N ## _write_xHEX_u64 (fstr ## N ##_t *s, uint64_t x, bool fw);   

_fstr_function_declarations(8);

#endif // _FSTR_H_
