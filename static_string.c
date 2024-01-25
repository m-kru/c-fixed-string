#include "static_string.h"

void sstr8_uint8_write(sstr8_t *s, uint8_t x) {
	snprintf(s->_buf + sstr_len(s), 8 - sstr_len(s), "%"PRIu8, x);
	while (s->_buf[sstr_len(s)] != 0)
		s->_str._len++;
}
