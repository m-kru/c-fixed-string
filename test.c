#include <assert.h>
#include <stdio.h>

#include "sstr.h"

void test_sstr8(void) {
	sstr8_init(s, "");
	assert(sstr_len(s) == 0);

	char c = ' ';
	sstr_write_char(&s, c);
	assert(sstr_len(s) == 1);

	uint8_t u8 = 0;
	sstr_write(&s, u8);
	assert(sstr_len(s) == 2);
}

void test_sstr8_no_space(void) {
	sstr8_init(s, "1234567");

	sstr_write_char(&s, 'a');

	sstr_write(&s, (uint8_t)0);
	sstr_write(&s, (uint8_t)10);
	sstr_write(&s, (uint8_t)100);
	sstr_write(&s, (uint8_t)255);
}

int main(int argc, char *argv[]) {
	test_sstr8();
	test_sstr8_no_space();

	return 0;
}
