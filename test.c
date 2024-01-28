#include <assert.h>
#include <stdio.h>

#include "sstr.h"

void test_sstr8(void) {
	sstr8_init(s, "");
	assert(sstr_len(s) == 0);

	char c = 's';
	sstr_write_char(&s, c);
	assert(sstr_len(s) == 1);
	sstr_println(s);

	char *string = "tring";
	sstr_write(&s, string);
	assert(sstr_len(s) == 6);
	sstr_println(s);

	uint8_t u8 = 0;
	sstr_write(&s, u8);
	assert(sstr_len(s) == 7);
	sstr_println(s);

	sstr_reset(&s);
	assert(sstr_len(s) == 0);

	uint16_t u16 = 1000;
	sstr_write(&s, u16);
	assert(sstr_len(s) == 4);
	sstr_println(s);
}

void test_sstr8_no_space(void) {
	sstr8_init(s, "12345");

	sstr_write(&s, (uint8_t)100);

	sstr_write_char(&s, '6');
	sstr_write(&s, (uint8_t)100);
	sstr_write(&s, (uint8_t)10);

	sstr_write_char(&s, '7');
	sstr_write(&s, (uint8_t)100);
	sstr_write(&s, (uint8_t)10);
	sstr_write(&s, (uint8_t)1);
	sstr_write_char(&s, 'A');
}

int main(int argc, char *argv[]) {
	test_sstr8();
	test_sstr8_no_space();

	return 0;
}
