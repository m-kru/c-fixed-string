#include <string.h>

#include "sstr.h"

#ifdef SSTR_DEFAULT_CB
void sstr_no_space_cb(
	const char * fn_name,
	const sstr_t * str,
	const sstr_arg_type_t arg_type,
	const void * arg
) {
	switch (arg_type) {
	case SSTR_CHAR:
		fprintf(
			SSTR_CB_STREAM,
			"%s: no buf space to write char '%c' to \"%s\"\n",
			fn_name, *((char *)arg), ((char *)str + sizeof(sstr_t))
		);
		break;
	case SSTR_STRING:
		fprintf(
			SSTR_CB_STREAM,
			"%s: no buf space to write \"%s\" to \"%s\"\n",
			fn_name, (char *)arg, ((char *)str + sizeof(sstr_t))
		);
		break;
	case SSTR_UINT8:
		fprintf(
			SSTR_CB_STREAM,
			"%s: no buf space to write uint8 '%" PRIu8 "' to \"%s\"\n",
			fn_name, *((uint8_t *)arg), ((char *)str + sizeof(sstr_t))
		);
		break;
	case SSTR_UINT16:
		fprintf(
			SSTR_CB_STREAM,
			"%s: no buf space to write uint16 '%" PRIu16 "' to \"%s\"\n",
			fn_name, *((uint16_t *)arg), ((char *)str + sizeof(sstr_t))
		);
		break;
	case SSTR_UINT32:
		fprintf(
			SSTR_CB_STREAM,
			"%s: no buf space to write uint32 '%" PRIu32 "' to \"%s\"\n",
			fn_name, *((uint32_t *)arg), ((char *)str + sizeof(sstr_t))
		);
		break;
	case SSTR_UINT64:
		fprintf(
			SSTR_CB_STREAM,
			"%s: no buf space to write uint64 '%" PRIu64 "' to \"%s\"\n",
			fn_name, *((uint64_t *)arg), ((char *)str + sizeof(sstr_t))
		);
		break;
	}
}
#endif

void sstr8_write_char(sstr8_t *s, char x) {
	if (sstr_len(s) < 7) {
		s->_buf[sstr_len(s)] = x;
		s->_str._len++;
	} else {
#ifdef SSTR_NO_SPACE_CB
		sstr_no_space_cb(__func__, (sstr_t *)s, SSTR_CHAR, &x);
#endif
	}
}

void sstr8_string_write(sstr8_t *s, char *x) {
	const uint8_t size = 8 - sstr_len(s);
	const size_t xlen = strlen(x);
	if (xlen > size) {
#ifdef SSTR_NO_SPACE_CB
		sstr_no_space_cb(__func__, (sstr_t *)s, SSTR_STRING, x);
#endif
		return;
	}
	snprintf(s->_buf + sstr_len(s), size, "%s", x);
	s->_str._len += xlen;
}

void sstr8_uint8_write(sstr8_t *s, uint8_t x) {
	char buf[4];
	const size_t size = snprintf(buf, sizeof(buf), "%"PRIu8, x);
	if (size >= 8 - sstr_len(s)) {
#ifdef SSTR_NO_SPACE_CB
		sstr_no_space_cb(__func__, (sstr_t *)s, SSTR_UINT8, &x);
#endif
		return;
	}
	sprintf(s->_buf + sstr_len(s), "%s", buf);
	s->_str._len += size;
}

void sstr8_uint16_write(sstr8_t *s, uint16_t x) {
	char buf[6];
	const size_t size = snprintf(buf, sizeof(buf), "%"PRIu16, x);
	if (size >= 8 - sstr_len(s)) {
#ifdef SSTR_NO_SPACE_CB
		sstr_no_space_cb(__func__, (sstr_t *)s, SSTR_UINT16, &x);
#endif
		return;
	}
	sprintf(s->_buf + sstr_len(s), "%s", buf);
	s->_str._len += size;
}

void sstr8_uint32_write(sstr8_t *s, uint32_t x) {
	char buf[11];
	const size_t size = snprintf(buf, sizeof(buf), "%"PRIu32, x);
	if (size >= 8 - sstr_len(s)) {
#ifdef SSTR_NO_SPACE_CB
		sstr_no_space_cb(__func__, (sstr_t *)s, SSTR_UINT32, &x);
#endif
		return;
	}
	sprintf(s->_buf + sstr_len(s), "%s", buf);
	s->_str._len += size;
}

void sstr8_uint64_write(sstr8_t *s, uint64_t x) {
	char buf[21];
	const size_t size = snprintf(buf, sizeof(buf), "%"PRIu64, x);
	if (size >= 8 - sstr_len(s)) {
#ifdef SSTR_NO_SPACE_CB
		sstr_no_space_cb(__func__, (sstr_t *)s, SSTR_UINT64, &x);
#endif
		return;
	}
	sprintf(s->_buf + sstr_len(s), "%s", buf);
	s->_str._len += size;
}
