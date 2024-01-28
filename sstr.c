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
			"%s: not enough space to write char '%c' to string \"%s\"\n",
			fn_name, *((char *)arg), ((char *)str + sizeof(sstr_t))
		);
		break;
	case SSTR_UINT8:
		fprintf(
			SSTR_CB_STREAM,
			"%s: not enough space to write uint8 '%u' to string \"%s\"\n",
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
#ifdef SSTR_NO_SPACE_CB
	uint8_t space = (8 - 1) - sstr_len(s);
	if ((x < 10 && space < 1) || (x < 100 && space < 2)|| (x < 1000 && space < 3))
		sstr_no_space_cb(__func__, (sstr_t *)s, SSTR_UINT8, &x);
#endif
	snprintf(s->_buf + sstr_len(s), 8 - sstr_len(s), "%"PRIu8, x);
	while (s->_buf[sstr_len(s)] != 0)
		s->_str._len++;
}
