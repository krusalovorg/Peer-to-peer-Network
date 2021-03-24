#include "edit_strings.h"
#include <iostream>

std::string lower(std::string str) {

	std::transform(str.begin(), str.end(), str.begin(), tolower);

	return str;
}

std::string split(std::string str,std::string symbol, int index)
{
    std::string result = str.substr(index, str.find(symbol));

    return result;
}

std::string charToString(char* str)
{
    std::string result;
    result = (const char*)str;
    return result;
}
