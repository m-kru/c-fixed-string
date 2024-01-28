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
	case SSTR_UINT8:
		fprintf(
			SSTR_CB_STREAM,
			"%s: no buf space to write uint8 '%u' to \"%s\"\n",
			fn_name, *((uint8_t *)arg), ((char *)str + sizeof(sstr_t))
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

void sstr8_uint8_write(sstr8_t *s, uint8_t x) {
	const uint8_t size = 8 - sstr_len(s);
	if ((x < 10 && size < 2) || (x < 100 && size < 3)|| (x < 1000 && size < 4)) {
#ifdef SSTR_NO_SPACE_CB
		sstr_no_space_cb(__func__, (sstr_t *)s, SSTR_UINT8, &x);
#endif
		return;
	}
	snprintf(s->_buf + sstr_len(s), size, "%"PRIu8, x);
	while (s->_buf[sstr_len(s)] != 0)
		s->_str._len++;
}
