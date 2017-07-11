/*
 * Base64.h
 *
 *  Created on: 6 Tem 2017
 *      Author: cagdasko
 */

#ifndef BASE64_H_
#define BASE64_H_

#include <vector>

class Base64 {
public:
	static char base64set[];

	Base64();
	virtual ~Base64();

	std::vector<char> encode(const char *data, std::size_t len);
};

#endif /* BASE64_H_ */
