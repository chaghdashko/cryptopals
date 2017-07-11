/*
 * Base64.cpp
 *
 *  Created on: 6 Tem 2017
 *      Author: cagdasko
 */

#include <iostream>

#include "Base64.h"

char Base64::base64set[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

Base64::Base64() {
	// TODO Auto-generated constructor stub

}

Base64::~Base64() {
	// TODO Auto-generated destructor stub
}

std::vector<char> Base64::encode(const char *data, std::size_t len) {
	std::vector<char> encodedBytes;
	char b;

	for (std::size_t i = 0; i < len; i += 3) {

		// get first 6 bits from chunk
		b = (data[i] & 0xFC) >> 2;
		encodedBytes.push_back(Base64::base64set[(int) b]);

		b = (data[i] & 0x03) << 4;

		if ((i + 1) < len) {

			// get second 6 bits from chunk
			b |= ((data[i + 1] & 0xF0) >> 4);
			encodedBytes.push_back(Base64::base64set[(int) b]);

			b = (data[i + 1] & 0x0F) << 2;

			if ((i + 2) < len) {

				// get third 6 bits from chunk
				b |= ((data[i + 2] & 0xC0) >> 6);
				encodedBytes.push_back(Base64::base64set[(int) b]);

				// get fourth 6 bits from chunk
				b = data[i + 2] & 0x3F;
				encodedBytes.push_back(Base64::base64set[(int) b]);
			} else {
				encodedBytes.push_back(Base64::base64set[(int) b]);

				// append '=' character at the end, as padding byte
				encodedBytes.push_back(0x3D);
			}
		} else {
			encodedBytes.push_back(Base64::base64set[(int) b]);

			// append two '=' characters at the end, as padding bytes
			encodedBytes.push_back(0x3D);
			encodedBytes.push_back(0x3D);
		}
	}

	return encodedBytes;
}
