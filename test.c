#include <assert.h>
#include <stdio.h>

#include "static_string.h"

void test_sstr8(void) {
	sstr8_init(s, "");
	assert(sstr_len(s) == 0);

	uint8_t u8 = 17;
	sstr_write(&s, u8);
	assert(sstr_len(s) == 2);
}

int main(int argc, char *argv[]) {
	test_sstr8();

	return 0;
}
