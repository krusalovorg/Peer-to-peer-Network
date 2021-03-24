#include "input.h"
#include <iostream>

std::string input(std::string str) {
    char output_inp[80]{};
    std::cout << str;
    std::cin.getline(output_inp, 80);
    return output_inp;
}