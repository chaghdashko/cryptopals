/*
 * PrettyPrint.cpp
 *
 *  Created on: 7 Tem 2017
 *      Author: cagdasko
 */

#include <string>
#include <iostream>

#include "PrettyPrint.h"

void PrettyPrint::print(const std::vector<char>& v) {
	std::string s = "";

	for (auto c : v) {
		s += c;
	}

	std::cout << s << std::endl;
}
