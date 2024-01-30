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

void sstr8_bool_write(sstr8_t *s, bool x) {
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

void sstr8_string_write(sstr8_t *s, char *x) {
	const uint8_t size = 8 - sstr_len(s);
	const size_t xlen = strlen(x);
	if (xlen > size) {
#ifdef SSTR_NO_SPACE_CB
		sstr_no_space_cb(__func__, (sstr_t *)s, x);
#endif
		return;
	}
	snprintf(s->_buf + sstr_len(s), size, "%s", x);
	s->_str._len += xlen;
}

void sstr8_u8_write(sstr8_t *s, uint8_t x) {
	char buf[4];
	const size_t size = snprintf(buf, sizeof(buf), "%"PRIu8, x);
	if (size >= 8 - sstr_len(s)) {
#ifdef SSTR_NO_SPACE_CB
		sstr_no_space_cb(__func__, (sstr_t *)s, buf);
#endif
		return;
	}
	sprintf(s->_buf + sstr_len(s), "%s", buf);
	s->_str._len += size;
}

void sstr8_u16_write(sstr8_t *s, uint16_t x) {
	char buf[6];
	const size_t size = snprintf(buf, sizeof(buf), "%"PRIu16, x);
	if (size >= 8 - sstr_len(s)) {
#ifdef SSTR_NO_SPACE_CB
		sstr_no_space_cb(__func__, (sstr_t *)s, buf);
#endif
		return;
	}
	sprintf(s->_buf + sstr_len(s), "%s", buf);
	s->_str._len += size;
}

void sstr8_u32_write(sstr8_t *s, uint32_t x) {
	char buf[11];
	const size_t size = snprintf(buf, sizeof(buf), "%"PRIu32, x);
	if (size >= 8 - sstr_len(s)) {
#ifdef SSTR_NO_SPACE_CB
		sstr_no_space_cb(__func__, (sstr_t *)s, buf);
#endif
		return;
	}
	sprintf(s->_buf + sstr_len(s), "%s", buf);
	s->_str._len += size;
}

void sstr8_u64_write(sstr8_t *s, uint64_t x) {
	char buf[21];
	const size_t size = snprintf(buf, sizeof(buf), "%"PRIu64, x);
	if (size >= 8 - sstr_len(s)) {
#ifdef SSTR_NO_SPACE_CB
		sstr_no_space_cb(__func__, (sstr_t *)s, buf);
#endif
		return;
	}
	sprintf(s->_buf + sstr_len(s), "%s", buf);
	s->_str._len += size;
}
