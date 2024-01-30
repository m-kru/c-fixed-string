#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "sstr.h"

void test_sstr8(void) {
	printf("running str8_t tests\n");

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

	sstr_reset(&s);
	assert(sstr_len(s) == 0);

	uint32_t u32 = 1234567;
	sstr_write(&s, u32);
	assert(sstr_len(s) == 7);
	sstr_println(s);

	sstr_reset(&s);
	assert(sstr_len(s) == 0);

	uint64_t u64 = 9999999;
	sstr_write(&s, u64);
	assert(sstr_len(s) == 7);
	sstr_println(s);

	sstr_reset(&s);
	assert(sstr_len(s) == 0);

	bool b = true;
	sstr_write(&s, b);
	assert(sstr_len(s) == 4);
	sstr_println(s);

	sstr_reset(&s);
	assert(sstr_len(s) == 0);

	b = false;
	sstr_write(&s, b);
	assert(sstr_len(s) == 5);
	sstr_println(s);

	sstr_reset(&s);
	assert(sstr_len(s) == 0);

	int8_t i8 = -111;
	sstr_write(&s, i8);
	assert(sstr_len(s) == 4);
	sstr_println(s);

	i8 = 113;
	sstr_write(&s, i8);
	assert(sstr_len(s) == 7);
	sstr_println(s);

	sstr_reset(&s);
	assert(sstr_len(s) == 0);

	int16_t i16 = -31456;
	sstr_write(&s, i16);
	assert(sstr_len(s) == 6);
	sstr_println(s);

	sstr_reset(&s);
	assert(sstr_len(s) == 0);

	i16 = 32000;
	sstr_write(&s, i16);
	assert(sstr_len(s) == 5);
	sstr_println(s);
}

void test_sstr8_no_space(void) {
	fprintf(stderr, "running str8_t no space tests\n");
	sstr8_init(s, "12345");

	sstr_write(&s, (bool)0);
	sstr_write(&s, (bool)1);
	sstr_write(&s, (uint8_t)100);
	sstr_write(&s, (int8_t)(-100));
	sstr_write(&s, (int8_t)(-99));
	sstr_write(&s, (int16_t)(-1000));
	sstr_write(&s, (int16_t)(32000));

	sstr_write_char(&s, '6');
	sstr_write(&s, (uint8_t)100);
	sstr_write(&s, (uint8_t)10);
	sstr_write(&s, (int8_t)(-7));

	sstr_write_char(&s, '7');
	sstr_write(&s, (uint8_t)100);
	sstr_write(&s, (uint8_t)10);
	sstr_write(&s, (uint8_t)1);
	sstr_write_char(&s, 'A');

	sstr_reset(&s);
	assert(sstr_len(s) == 0);
	sstr_write(&s, (uint32_t)10000000);
	sstr_write(&s, (uint64_t)99999999);
}

int main(int argc, char *argv[]) {
	test_sstr8();
	test_sstr8_no_space();

	return 0;
}
