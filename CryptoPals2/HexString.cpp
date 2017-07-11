/*
 * HexString.cpp
 *
 *  Created on: 10 Tem 2017
 *      Author: cagdasko
 */

#include <cstdlib>
#include "HexString.h"

void HexString::convertToByteArray(const char *hexData, size_t len, char *out) {
	for (unsigned int i = 0, j = 0; i < len; i += 2, j++) {
		sscanf(hexData + i, "%2hhx", &out[j]);
	}
}
