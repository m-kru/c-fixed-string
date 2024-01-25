#include "static_string.h"

void sstr8_write_char(sstr8_t *s, char x) {
	if (sstr_len(s) < 7) {
		s->_buf[sstr_len(s)] = x;
		s->_str._len++;
	}
}

void sstr8_uint8_write(sstr8_t *s, uint8_t x) {
	snprintf(s->_buf + sstr_len(s), 8 - sstr_len(s), "%"PRIu8, x);
	while (s->_buf[sstr_len(s)] != 0)
		s->_str._len++;
}
