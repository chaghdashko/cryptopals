/*
 * HexString.h
 *
 *  Created on: 10 Tem 2017
 *      Author: cagdasko
 */

#ifndef HEXSTRING_H_
#define HEXSTRING_H_

#include <string>

class HexString {
public:
	void convertToByteArray(const char *hexData, size_t len, char *out);
};

#endif /* HEXSTRING_H_ */
