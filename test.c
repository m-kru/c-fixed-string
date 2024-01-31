#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "sstr.h"

void test_sstr8(void) {
	printf("\nRunning str8_t tests\n");
	sstr8_init(s, "");
	assert(sstr_len(s) == 0);

	printf("Testing char write\n");
	sstr_write_char(&s, 'a');
	assert(sstr_len(s) == 1);
	sstr_println(s);
	sstr_write_char(&s, 'b');
	assert(sstr_len(s) == 2);
	sstr_println(s);

	printf("Testing bool write\n");
	sstr_reset(&s);
	sstr_write(&s, (bool)true);
	assert(sstr_len(s) == 4);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write(&s, (bool)false);
	assert(sstr_len(s) == 5);
	sstr_println(s);

	printf("Testing string (char *) write\n");
	sstr_reset(&s);
	char *string = "string";
	sstr_write(&s, string);
	assert(sstr_len(s) == 6);
	sstr_println(s);

	printf("Testing uint8_t write\n");
	sstr_reset(&s);
	sstr_write(&s, (uint8_t)0);
	assert(sstr_len(s) == 1);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write(&s, (uint8_t)10);
	assert(sstr_len(s) == 2);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write(&s, (uint8_t)255);
	assert(sstr_len(s) == 3);
	sstr_println(s);

	printf("Testing uint16_t write\n");
	sstr_reset(&s);
	sstr_write(&s, (uint16_t)7);
	assert(sstr_len(s) == 1);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write(&s, (uint16_t)12);
	assert(sstr_len(s) == 2);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write(&s, (uint16_t)300);
	assert(sstr_len(s) == 3);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write(&s, (uint16_t)4987);
	assert(sstr_len(s) == 4);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write(&s, (uint16_t)65535);
	assert(sstr_len(s) == 5);
	sstr_println(s);

	printf("Testing uint32_t write\n");
	sstr_reset(&s);
	sstr_write(&s, (uint32_t)1);
	assert(sstr_len(s) == 1);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write(&s, (uint32_t)4321);
	assert(sstr_len(s) == 4);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write(&s, (uint32_t)1234567);
	assert(sstr_len(s) == 7);
	sstr_println(s);

	printf("Testing uint64_t write\n");
	sstr_reset(&s);
	sstr_write(&s, (uint64_t)1);
	assert(sstr_len(s) == 1);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write(&s, (uint64_t)12345);
	assert(sstr_len(s) == 5);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write(&s, (uint64_t)1234567);
	assert(sstr_len(s) == 7);
	sstr_println(s);

	printf("Testing int8_t write\n");
	sstr_reset(&s);
	sstr_write(&s, (int8_t)1);
	assert(sstr_len(s) == 1);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write(&s, (int8_t)-1);
	assert(sstr_len(s) == 2);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write(&s, (int8_t)20);
	assert(sstr_len(s) == 2);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write(&s, (int8_t)-20);
	assert(sstr_len(s) == 3);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write(&s, (int8_t)INT8_MAX);
	assert(sstr_len(s) == 3);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write(&s, (int8_t)INT8_MIN);
	assert(sstr_len(s) == 4);
	sstr_println(s);

	printf("Testing int16_t write\n");
	sstr_reset(&s);
	sstr_write(&s, (int16_t)2);
	assert(sstr_len(s) == 1);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write(&s, (int16_t)-2);
	assert(sstr_len(s) == 2);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write(&s, (int16_t)400);
	assert(sstr_len(s) == 3);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write(&s, (int16_t)-400);
	assert(sstr_len(s) == 4);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write(&s, (int16_t)INT16_MAX);
	assert(sstr_len(s) == 5);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write(&s, (int16_t)INT16_MIN);
	assert(sstr_len(s) == 6);
	sstr_println(s);

	printf("Testing int32_t write\n");
	sstr_reset(&s);
	sstr_write(&s, (int32_t)3);
	assert(sstr_len(s) == 1);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write(&s, (int32_t)-3);
	assert(sstr_len(s) == 2);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write(&s, (int32_t)123456);
	assert(sstr_len(s) == 6);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write(&s, (int32_t)-12345);
	assert(sstr_len(s) == 6);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write(&s, (int32_t)1234567);
	assert(sstr_len(s) == 7);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write(&s, (int32_t)-123456);
	assert(sstr_len(s) == 7);
	sstr_println(s);

	printf("Testing int64_t write\n");
	sstr_reset(&s);
	sstr_write(&s, (int64_t)9);
	assert(sstr_len(s) == 1);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write(&s, (int64_t)-9);
	assert(sstr_len(s) == 2);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write(&s, (int64_t)1236);
	assert(sstr_len(s) == 4);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write(&s, (int64_t)-1234);
	assert(sstr_len(s) == 5);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write(&s, (int64_t)7654321);
	assert(sstr_len(s) == 7);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write(&s, (int64_t)-123456);
	assert(sstr_len(s) == 7);
	sstr_println(s);

	printf("Testing float write\n");
	sstr_reset(&s);
	sstr_write_float(&s, (float)12.9876, 2);
	assert(sstr_len(s) == 5);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write_float(&s, (float)23.7, 1);
	assert(sstr_len(s) == 4);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write_float(&s, (float)(-141.11), 2);
	assert(sstr_len(s) == 7);
	sstr_println(s);

	printf("Testing double write\n");
	sstr_reset(&s);
	sstr_write_float(&s, (double)12.986, 2);
	assert(sstr_len(s) == 5);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write_float(&s, (double)23.7, 1);
	assert(sstr_len(s) == 4);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write_float(&s, (double)(-294.11), 2);
	assert(sstr_len(s) == 7);
	sstr_println(s);

	printf("Testing uint8_t hex write\n");
	sstr_reset(&s);
	sstr_write_hex(&s, (uint8_t)0xf, false);
	assert(sstr_len(s) == 1);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write_hex(&s, (uint8_t)0xf, true);
	assert(sstr_len(s) == 2);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write_hex(&s, (uint8_t)0xee, true);
	assert(sstr_len(s) == 2);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write_hex(&s, (uint8_t)0xee, false);
	assert(sstr_len(s) == 2);
	sstr_println(s);

	printf("Testing uint16_t hex write\n");
	sstr_reset(&s);
	sstr_write_hex(&s, (uint16_t)0xbcd, false);
	assert(sstr_len(s) == 3);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write_hex(&s, (uint16_t)0xbcd, true);
	assert(sstr_len(s) == 4);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write_hex(&s, (uint16_t)0x0, true);
	assert(sstr_len(s) == 4);
	sstr_println(s);
	sstr_reset(&s);
	sstr_write_hex(&s, (uint16_t)0xabcd, false);
	assert(sstr_len(s) == 4);
	sstr_println(s);
}

void test_sstr8_no_space(void) {
	fprintf(stderr, "\nRunning str8_t no space tests\n");
	sstr8_init(s, "12345");

	sstr_write(&s, (bool)0);
	sstr_write(&s, (bool)1);
	sstr_write(&s, (uint8_t)100);
	sstr_write(&s, (int8_t)(-100));
	sstr_write(&s, (int8_t)(-99));
	sstr_write(&s, (int16_t)(-1000));
	sstr_write(&s, (int16_t)(32000));
	sstr_write_float(&s, (float)(123.486790), 10);
	sstr_write_double(&s, (double)(123.486790), 10);
	sstr_write_hex(&s, (uint16_t)0xee, true);

	sstr_write_char(&s, '6');
	sstr_write(&s, (uint8_t)100);
	sstr_write(&s, (uint8_t)10);
	sstr_write(&s, (int8_t)(-7));
	sstr_write_hex(&s, (uint8_t)0xee, true);

	sstr_write_char(&s, '7');
	sstr_write(&s, (uint8_t)100);
	sstr_write(&s, (uint8_t)10);
	sstr_write(&s, (uint8_t)1);
	sstr_write_char(&s, 'A');
	sstr_write_hex(&s, (uint8_t)0x0, false);

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
