/*
 * Base64Test.cpp
 *
 *  Created on: 6 Tem 2017
 *      Author: cagdasko
 */

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cassert>
#include <CUnit/Basic.h>

#include "../Base64.h"
#include "../PrettyPrint/PrettyPrint.h"
#include "../HexString.h"

std::string hexData = "";
const char *expectedResult = NULL;

static bool assertTrue(std::vector<char> encodedBytes, const char *expectedResult, size_t len) {
	if (encodedBytes.size() != len)
		return false;

	for (unsigned int i = 0; i < len; i++) {
		if (encodedBytes[i] != *(expectedResult + i))
			return false;
	}

	return true;
}

int init_suite(void) {
	return 0;
}

int clean_suite(void) {
	return 0;
}

void testBase64Encode() {
	const char *hexData = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
	const char *expectedResult = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";

	size_t len = strlen(hexData) / 2;
	char out[len] = { 0 };
	HexString hexString;
	hexString.convertToByteArray(hexData, strlen(hexData), out);

	Base64 base64;
	std::vector<char> encodedBytes = base64.encode(out, len);

	PrettyPrint::print(encodedBytes);

	CU_ASSERT(assertTrue(encodedBytes, expectedResult, strlen(expectedResult)));
}

int main(int argc, char **argv) {
	CU_pSuite suite = NULL;

	/* initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	/* add a suite to the registry */
	suite = CU_add_suite("Suite_1", init_suite, clean_suite);

	if (NULL == suite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* add the tests to the suite */
	if (NULL == CU_add_test(suite, "testBase64Encode", testBase64Encode)) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* Run all tests using the CUnit Basic interface */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

	return CU_get_error();
}
