// SPDX-License-Identifier: MIT
// https://github.com/m-kru/c-sstr
// Copyright (c) 2024 Michał Kruszewski

#include <string.h>

#include "sstr.h"

#ifdef SSTR_DEFAULT_CB
void sstr_no_space_cb(
	const char * fn_name,
	const sstr_t * str,
	const char * arg
) {
	fprintf(
		SSTR_CB_STREAM,
		"%s: no buf space to write \"%s\" to \"%s\"\n",
		fn_name, arg, ((char *)str + sizeof(sstr_t))
	);
}
#endif

void sstr8_write_char(sstr8_t *s, char x) {
	if (sstr_len(s) < 7) {
		s->_buf[sstr_len(s)] = x;
		s->_str._len++;
	} else {
#ifdef SSTR_NO_SPACE_CB
		char buf[2] = {0};
		buf[0] = x;
		sstr_no_space_cb(__func__, (sstr_t *)s, buf);
#endif
	}
}

void sstr8_write_float(sstr8_t *s, float x, uint8_t p) {
	char buf[32];
	const size_t size = snprintf(buf, sizeof(buf), "%.*f", p, x);
	if (size >= 8 - sstr_len(s)) {
#ifdef SSTR_NO_SPACE_CB
		sstr_no_space_cb(__func__, (sstr_t *)s, buf);
#endif
		return;
	}
	sprintf(s->_buf + sstr_len(s), "%s", buf);
	s->_str._len += size;
}

void sstr8_write_double(sstr8_t *s, double x, uint8_t p) {
	char buf[64];
	const size_t size = snprintf(buf, sizeof(buf), "%.*lf", p, x);
	if (size >= 8 - sstr_len(s)) {
#ifdef SSTR_NO_SPACE_CB
		sstr_no_space_cb(__func__, (sstr_t *)s, buf);
#endif
		return;
	}
	sprintf(s->_buf + sstr_len(s), "%s", buf);
	s->_str._len += size;
}

void sstr8_write_bool(sstr8_t *s, bool x) {
	const char *buf = (x) ? "true" : "false";
	const uint8_t size = (x) ? 4 : 5;
	if (size >= 8 - sstr_len(s)) {
#ifdef SSTR_NO_SPACE_CB
		sstr_no_space_cb(__func__, (sstr_t *)s, buf);
#endif
		return;
	}
	sprintf(s->_buf + sstr_len(s),"%s", buf);
	s->_str._len += size;
}

void sstr8_write_string(sstr8_t *s, char *x) {
	const uint8_t size = strlen(x);
	if (size >= 8 - sstr_len(s)) {
#ifdef SSTR_NO_SPACE_CB
		sstr_no_space_cb(__func__, (sstr_t *)s, x);
#endif
		return;
	}
	sprintf(s->_buf + sstr_len(s), "%s", x);
	s->_str._len += size;
}

void sstr8_write_u8(sstr8_t *s, uint8_t x) {
	char buf[4];
	const size_t size = sprintf(buf, "%"PRIu8, x);
	if (size >= 8 - sstr_len(s)) {
#ifdef SSTR_NO_SPACE_CB
		sstr_no_space_cb(__func__, (sstr_t *)s, buf);
#endif
		return;
	}
	sprintf(s->_buf + sstr_len(s), "%s", buf);
	s->_str._len += size;
}

void sstr8_write_u16(sstr8_t *s, uint16_t x) {
	char buf[6];
	const size_t size = sprintf(buf, "%"PRIu16, x);
	if (size >= 8 - sstr_len(s)) {
#ifdef SSTR_NO_SPACE_CB
		sstr_no_space_cb(__func__, (sstr_t *)s, buf);
#endif
		return;
	}
	sprintf(s->_buf + sstr_len(s), "%s", buf);
	s->_str._len += size;
}

void sstr8_write_u32(sstr8_t *s, uint32_t x) {
	char buf[11];
	const size_t size = sprintf(buf, "%"PRIu32, x);
	if (size >= 8 - sstr_len(s)) {
#ifdef SSTR_NO_SPACE_CB
		sstr_no_space_cb(__func__, (sstr_t *)s, buf);
#endif
		return;
	}
	sprintf(s->_buf + sstr_len(s), "%s", buf);
	s->_str._len += size;
}

void sstr8_write_u64(sstr8_t *s, uint64_t x) {
	char buf[21];
	const size_t size = sprintf(buf, "%"PRIu64, x);
	if (size >= 8 - sstr_len(s)) {
#ifdef SSTR_NO_SPACE_CB
		sstr_no_space_cb(__func__, (sstr_t *)s, buf);
#endif
		return;
	}
	sprintf(s->_buf + sstr_len(s), "%s", buf);
	s->_str._len += size;
}

void sstr8_write_i8(sstr8_t *s, int8_t x) {
	char buf[5];
	const size_t size = sprintf(buf, "%"PRIi8, x);
	if (size >= 8 - sstr_len(s)) {
#ifdef SSTR_NO_SPACE_CB
		sstr_no_space_cb(__func__, (sstr_t *)s, buf);
#endif
		return;
	}
	sprintf(s->_buf + sstr_len(s), "%s", buf);
	s->_str._len += size;
}

void sstr8_write_i16(sstr8_t *s, int16_t x) {
	char buf[7];
	const size_t size = sprintf(buf, "%"PRIi16, x);
	if (size >= 8 - sstr_len(s)) {
#ifdef SSTR_NO_SPACE_CB
		sstr_no_space_cb(__func__, (sstr_t *)s, buf);
#endif
		return;
	}
	sprintf(s->_buf + sstr_len(s), "%s", buf);
	s->_str._len += size;
}

void sstr8_write_i32(sstr8_t *s, int32_t x) {
	char buf[12];
	const size_t size = sprintf(buf, "%"PRIi32, x);
	if (size >= 8 - sstr_len(s)) {
#ifdef SSTR_NO_SPACE_CB
		sstr_no_space_cb(__func__, (sstr_t *)s, buf);
#endif
		return;
	}
	sprintf(s->_buf + sstr_len(s), "%s", buf);
	s->_str._len += size;
}

void sstr8_write_i64(sstr8_t *s, int64_t x) {
	char buf[22];
	const size_t size = sprintf(buf, "%"PRIi64, x);
	if (size >= 8 - sstr_len(s)) {
#ifdef SSTR_NO_SPACE_CB
		sstr_no_space_cb(__func__, (sstr_t *)s, buf);
#endif
		return;
	}
	sprintf(s->_buf + sstr_len(s), "%s", buf);
	s->_str._len += size;
}

void sstr8_write_hex_u8(sstr8_t *s, uint8_t x, bool fw) {
	char buf[3];
	const size_t size = sprintf(buf, (fw) ? "%02"PRIx8 : "%"PRIx8, x);
	if (size >= 8 - sstr_len(s)) {
#ifdef SSTR_NO_SPACE_CB
		sstr_no_space_cb(__func__, (sstr_t *)s, buf);
#endif
		return;
	}
	sprintf(s->_buf + sstr_len(s), "%s", buf);
	s->_str._len += size;
}

void sstr8_write_hex_u16(sstr8_t *s, uint16_t x, bool fw) {
	char buf[5];
	const size_t size = sprintf(buf, (fw) ? "%04"PRIx16 : "%"PRIx16, x);
	if (size >= 8 - sstr_len(s)) {
#ifdef SSTR_NO_SPACE_CB
		sstr_no_space_cb(__func__, (sstr_t *)s, buf);
#endif
		return;
	}
	sprintf(s->_buf + sstr_len(s), "%s", buf);
	s->_str._len += size;
}

void sstr8_write_hex_u32(sstr8_t *s, uint32_t x, bool fw) {
	char buf[9];
	const size_t size = sprintf(buf, (fw) ? "%08"PRIx32 : "%"PRIx32, x);
	if (size >= 8 - sstr_len(s)) {
#ifdef SSTR_NO_SPACE_CB
		sstr_no_space_cb(__func__, (sstr_t *)s, buf);
#endif
		return;
	}
	sprintf(s->_buf + sstr_len(s), "%s", buf);
	s->_str._len += size;
}

void sstr8_write_hex_u64(sstr8_t *s, uint64_t x, bool fw) {
	char buf[17];
	const size_t size = sprintf(buf, (fw) ? "%016"PRIx64 : "%"PRIx64, x);
	if (size >= 8 - sstr_len(s)) {
#ifdef SSTR_NO_SPACE_CB
		sstr_no_space_cb(__func__, (sstr_t *)s, buf);
#endif
		return;
	}
	sprintf(s->_buf + sstr_len(s), "%s", buf);
	s->_str._len += size;
}
