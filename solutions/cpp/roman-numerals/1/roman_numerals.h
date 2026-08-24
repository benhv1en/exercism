#pragma once

#include <map>
#include <stack>
#include <string>

std::stack<unsigned int> ComponentOf(unsigned int);

const std::map<unsigned int, char> kRomanianVersionOf{
    {1000, 'M'}, {500, 'D'}, {100, 'C'}, {50, 'L'},
    {10, 'X'},   {5, 'V'},   {1, 'I'}

};

namespace roman_numerals {
std::string convert(const unsigned int&);
}
