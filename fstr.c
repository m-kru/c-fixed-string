// SPDX-License-Identifier: MIT
// https://github.com/m-kru/c-fstr
// Copyright (c) 2024 Michał Kruszewski

#include <string.h>

#include "fstr.h"

#ifdef FSTR_DEFAULT_CB
void fstr_no_space_cb(
	const char * fn_name,
	const fstr_t * str,
	const char * arg
) {
	fprintf(
		FSTR_CB_STREAM,
		"%s: no buf space to write \"%s\" to \"%s\"\n",
		fn_name, arg, ((char *)str + sizeof(fstr_t))
	);
}
#endif

void fstr8_write_char(fstr8_t *s, char x) {
	if (fstr_len(s) < 7) {
		s->_buf[fstr_len(s)] = x;
		s->_str._len++;
	} else {
#ifdef FSTR_NO_SPACE_CB
		char buf[2] = {0};
		buf[0] = x;
		fstr_no_space_cb(__func__, (fstr_t *)s, buf);
#endif
	}
}

void fstr8_write_float(fstr8_t *s, float x, uint8_t p) {
	char buf[32];
	const size_t size = snprintf(buf, sizeof(buf), "%.*f", p, x);
	if (size >= 8 - fstr_len(s)) {
#ifdef FSTR_NO_SPACE_CB
		fstr_no_space_cb(__func__, (fstr_t *)s, buf);
#endif
		return;
	}
	memcpy(s->_buf + fstr_len(s), buf, size + 1);
	s->_str._len += size;
}

void fstr8_write_double(fstr8_t *s, double x, uint8_t p) {
	char buf[64];
	const size_t size = snprintf(buf, sizeof(buf), "%.*lf", p, x);
	if (size >= 8 - fstr_len(s)) {
#ifdef FSTR_NO_SPACE_CB
		fstr_no_space_cb(__func__, (fstr_t *)s, buf);
#endif
		return;
	}
	memcpy(s->_buf + fstr_len(s), buf, size + 1);
	s->_str._len += size;
}

void fstr8_write_bool(fstr8_t *s, bool x) {
	const char *buf = (x) ? "true" : "false";
	const uint8_t size = (x) ? 4 : 5;
	if (size >= 8 - fstr_len(s)) {
#ifdef FSTR_NO_SPACE_CB
		fstr_no_space_cb(__func__, (fstr_t *)s, buf);
#endif
		return;
	}
	memcpy(s->_buf + fstr_len(s), buf, size + 1);
	s->_str._len += size;
}

void fstr8_write_string(fstr8_t *s, char *x) {
	const uint8_t size = strlen(x);
	if (size >= 8 - fstr_len(s)) {
#ifdef FSTR_NO_SPACE_CB
		fstr_no_space_cb(__func__, (fstr_t *)s, x);
#endif
		return;
	}
	memcpy(s->_buf + fstr_len(s), x, size + 1);
	s->_str._len += size;
}

void fstr8_write_u8(fstr8_t *s, uint8_t x) {
	char buf[4];
	const size_t size = sprintf(buf, "%"PRIu8, x);
	if (size >= 8 - fstr_len(s)) {
#ifdef FSTR_NO_SPACE_CB
		fstr_no_space_cb(__func__, (fstr_t *)s, buf);
#endif
		return;
	}
	memcpy(s->_buf + fstr_len(s), buf, size + 1);
	s->_str._len += size;
}

void fstr8_write_u16(fstr8_t *s, uint16_t x) {
	char buf[6];
	const size_t size = sprintf(buf, "%"PRIu16, x);
	if (size >= 8 - fstr_len(s)) {
#ifdef FSTR_NO_SPACE_CB
		fstr_no_space_cb(__func__, (fstr_t *)s, buf);
#endif
		return;
	}
	memcpy(s->_buf + fstr_len(s), buf, size + 1);
	s->_str._len += size;
}

void fstr8_write_u32(fstr8_t *s, uint32_t x) {
	char buf[11];
	const size_t size = sprintf(buf, "%"PRIu32, x);
	if (size >= 8 - fstr_len(s)) {
#ifdef FSTR_NO_SPACE_CB
		fstr_no_space_cb(__func__, (fstr_t *)s, buf);
#endif
		return;
	}
	memcpy(s->_buf + fstr_len(s), buf, size + 1);
	s->_str._len += size;
}

void fstr8_write_u64(fstr8_t *s, uint64_t x) {
	char buf[21];
	const size_t size = sprintf(buf, "%"PRIu64, x);
	if (size >= 8 - fstr_len(s)) {
#ifdef FSTR_NO_SPACE_CB
		fstr_no_space_cb(__func__, (fstr_t *)s, buf);
#endif
		return;
	}
	memcpy(s->_buf + fstr_len(s), buf, size + 1);
	s->_str._len += size;
}

void fstr8_write_i8(fstr8_t *s, int8_t x) {
	char buf[5];
	const size_t size = sprintf(buf, "%"PRIi8, x);
	if (size >= 8 - fstr_len(s)) {
#ifdef FSTR_NO_SPACE_CB
		fstr_no_space_cb(__func__, (fstr_t *)s, buf);
#endif
		return;
	}
	memcpy(s->_buf + fstr_len(s), buf, size + 1);
	s->_str._len += size;
}

void fstr8_write_i16(fstr8_t *s, int16_t x) {
	char buf[7];
	const size_t size = sprintf(buf, "%"PRIi16, x);
	if (size >= 8 - fstr_len(s)) {
#ifdef FSTR_NO_SPACE_CB
		fstr_no_space_cb(__func__, (fstr_t *)s, buf);
#endif
		return;
	}
	memcpy(s->_buf + fstr_len(s), buf, size + 1);
	s->_str._len += size;
}

void fstr8_write_i32(fstr8_t *s, int32_t x) {
	char buf[12];
	const size_t size = sprintf(buf, "%"PRIi32, x);
	if (size >= 8 - fstr_len(s)) {
#ifdef FSTR_NO_SPACE_CB
		fstr_no_space_cb(__func__, (fstr_t *)s, buf);
#endif
		return;
	}
	memcpy(s->_buf + fstr_len(s), buf, size + 1);
	s->_str._len += size;
}

void fstr8_write_i64(fstr8_t *s, int64_t x) {
	char buf[22];
	const size_t size = sprintf(buf, "%"PRIi64, x);
	if (size >= 8 - fstr_len(s)) {
#ifdef FSTR_NO_SPACE_CB
		fstr_no_space_cb(__func__, (fstr_t *)s, buf);
#endif
		return;
	}
	memcpy(s->_buf + fstr_len(s), buf, size + 1);
	s->_str._len += size;
}

void fstr8_write_hex_u8(fstr8_t *s, uint8_t x, bool fw) {
	char buf[3];
	const size_t size = sprintf(buf, (fw) ? "%02"PRIx8 : "%"PRIx8, x);
	if (size >= 8 - fstr_len(s)) {
#ifdef FSTR_NO_SPACE_CB
		fstr_no_space_cb(__func__, (fstr_t *)s, buf);
#endif
		return;
	}
	memcpy(s->_buf + fstr_len(s), buf, size + 1);
	s->_str._len += size;
}

void fstr8_write_hex_u16(fstr8_t *s, uint16_t x, bool fw) {
	char buf[5];
	const size_t size = sprintf(buf, (fw) ? "%04"PRIx16 : "%"PRIx16, x);
	if (size >= 8 - fstr_len(s)) {
#ifdef FSTR_NO_SPACE_CB
		fstr_no_space_cb(__func__, (fstr_t *)s, buf);
#endif
		return;
	}
	memcpy(s->_buf + fstr_len(s), buf, size + 1);
	s->_str._len += size;
}

void fstr8_write_hex_u32(fstr8_t *s, uint32_t x, bool fw) {
	char buf[9];
	const size_t size = sprintf(buf, (fw) ? "%08"PRIx32 : "%"PRIx32, x);
	if (size >= 8 - fstr_len(s)) {
#ifdef FSTR_NO_SPACE_CB
		fstr_no_space_cb(__func__, (fstr_t *)s, buf);
#endif
		return;
	}
	memcpy(s->_buf + fstr_len(s), buf, size + 1);
	s->_str._len += size;
}

void fstr8_write_hex_u64(fstr8_t *s, uint64_t x, bool fw) {
	char buf[17];
	const size_t size = sprintf(buf, (fw) ? "%016"PRIx64 : "%"PRIx64, x);
	if (size >= 8 - fstr_len(s)) {
#ifdef FSTR_NO_SPACE_CB
		fstr_no_space_cb(__func__, (fstr_t *)s, buf);
#endif
		return;
	}
	memcpy(s->_buf + fstr_len(s), buf, size + 1);
	s->_str._len += size;
}

void fstr8_write_xhex_u8(fstr8_t *s, uint8_t x, bool fw) {
	char buf[5];
	const size_t size = sprintf(buf, (fw) ? "0x%02"PRIx8 : "0x%"PRIx8, x);
	if (size >= 8 - fstr_len(s)) {
#ifdef FSTR_NO_SPACE_CB
		fstr_no_space_cb(__func__, (fstr_t *)s, buf);
#endif
		return;
	}
	memcpy(s->_buf + fstr_len(s), buf, size + 1);
	s->_str._len += size;
}

void fstr8_write_xhex_u16(fstr8_t *s, uint16_t x, bool fw) {
	char buf[7];
	const size_t size = sprintf(buf, (fw) ? "0x%04"PRIx16 : "0x%"PRIx16, x);
	if (size >= 8 - fstr_len(s)) {
#ifdef FSTR_NO_SPACE_CB
		fstr_no_space_cb(__func__, (fstr_t *)s, buf);
#endif
		return;
	}
	memcpy(s->_buf + fstr_len(s), buf, size + 1);
	s->_str._len += size;
}

void fstr8_write_xhex_u32(fstr8_t *s, uint32_t x, bool fw) {
	char buf[11];
	const size_t size = sprintf(buf, (fw) ? "0x%08"PRIx32 : "0x%"PRIx32, x);
	if (size >= 8 - fstr_len(s)) {
#ifdef FSTR_NO_SPACE_CB
		fstr_no_space_cb(__func__, (fstr_t *)s, buf);
#endif
		return;
	}
	memcpy(s->_buf + fstr_len(s), buf, size + 1);
	s->_str._len += size;
}

void fstr8_write_xhex_u64(fstr8_t *s, uint64_t x, bool fw) {
	char buf[19];
	const size_t size = sprintf(buf, (fw) ? "0x%016"PRIx64 : "0x%"PRIx64, x);
	if (size >= 8 - fstr_len(s)) {
#ifdef FSTR_NO_SPACE_CB
		fstr_no_space_cb(__func__, (fstr_t *)s, buf);
#endif
		return;
	}
	memcpy(s->_buf + fstr_len(s), buf, size + 1);
	s->_str._len += size;
}

void fstr8_write_HEX_u8(fstr8_t *s, uint8_t x, bool fw) {
	char buf[3];
	const size_t size = sprintf(buf, (fw) ? "%02"PRIX8 : "%"PRIX8, x);
	if (size >= 8 - fstr_len(s)) {
#ifdef FSTR_NO_SPACE_CB
		fstr_no_space_cb(__func__, (fstr_t *)s, buf);
#endif
		return;
	}
	memcpy(s->_buf + fstr_len(s), buf, size + 1);
	s->_str._len += size;
}

void fstr8_write_HEX_u16(fstr8_t *s, uint16_t x, bool fw) {
	char buf[5];
	const size_t size = sprintf(buf, (fw) ? "%04"PRIX16 : "%"PRIX16, x);
	if (size >= 8 - fstr_len(s)) {
#ifdef FSTR_NO_SPACE_CB
		fstr_no_space_cb(__func__, (fstr_t *)s, buf);
#endif
		return;
	}
	memcpy(s->_buf + fstr_len(s), buf, size + 1);
	s->_str._len += size;
}

void fstr8_write_HEX_u32(fstr8_t *s, uint32_t x, bool fw) {
	char buf[9];
	const size_t size = sprintf(buf, (fw) ? "%08"PRIX32 : "%"PRIX32, x);
	if (size >= 8 - fstr_len(s)) {
#ifdef FSTR_NO_SPACE_CB
		fstr_no_space_cb(__func__, (fstr_t *)s, buf);
#endif
		return;
	}
	memcpy(s->_buf + fstr_len(s), buf, size + 1);
	s->_str._len += size;
}

void fstr8_write_HEX_u64(fstr8_t *s, uint64_t x, bool fw) {
	char buf[17];
	const size_t size = sprintf(buf, (fw) ? "%016"PRIX64 : "%"PRIX64, x);
	if (size >= 8 - fstr_len(s)) {
#ifdef FSTR_NO_SPACE_CB
		fstr_no_space_cb(__func__, (fstr_t *)s, buf);
#endif
		return;
	}
	memcpy(s->_buf + fstr_len(s), buf, size + 1);
	s->_str._len += size;
}

void fstr8_write_xHEX_u8(fstr8_t *s, uint8_t x, bool fw) {
	char buf[5];
	const size_t size = sprintf(buf, (fw) ? "0x%02"PRIX8 : "0x%"PRIX8, x);
	if (size >= 8 - fstr_len(s)) {
#ifdef FSTR_NO_SPACE_CB
		fstr_no_space_cb(__func__, (fstr_t *)s, buf);
#endif
		return;
	}
	memcpy(s->_buf + fstr_len(s), buf, size + 1);
	s->_str._len += size;
}

void fstr8_write_xHEX_u16(fstr8_t *s, uint16_t x, bool fw) {
	char buf[7];
	const size_t size = sprintf(buf, (fw) ? "0x%04"PRIX16 : "0x%"PRIX16, x);
	if (size >= 8 - fstr_len(s)) {
#ifdef FSTR_NO_SPACE_CB
		fstr_no_space_cb(__func__, (fstr_t *)s, buf);
#endif
		return;
	}
	memcpy(s->_buf + fstr_len(s), buf, size + 1);
	s->_str._len += size;
}

void fstr8_write_xHEX_u32(fstr8_t *s, uint32_t x, bool fw) {
	char buf[11];
	const size_t size = sprintf(buf, (fw) ? "0x%08"PRIX32 : "0x%"PRIX32, x);
	if (size >= 8 - fstr_len(s)) {
#ifdef FSTR_NO_SPACE_CB
		fstr_no_space_cb(__func__, (fstr_t *)s, buf);
#endif
		return;
	}
	memcpy(s->_buf + fstr_len(s), buf, size + 1);
	s->_str._len += size;
}

void fstr8_write_xHEX_u64(fstr8_t *s, uint64_t x, bool fw) {
	char buf[19];
	const size_t size = sprintf(buf, (fw) ? "0x%016"PRIX64 : "0x%"PRIX64, x);
	if (size >= 8 - fstr_len(s)) {
#ifdef FSTR_NO_SPACE_CB
		fstr_no_space_cb(__func__, (fstr_t *)s, buf);
#endif
		return;
	}
	memcpy(s->_buf + fstr_len(s), buf, size + 1);
	s->_str._len += size;
}
