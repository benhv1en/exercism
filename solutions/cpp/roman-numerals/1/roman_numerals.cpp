#include "roman_numerals.h"

std::stack<unsigned int> ComponentOf(unsigned int number) {
  std::stack<unsigned int> components;
  unsigned int decimal = 1;
  while (number != 0) {
    components.push(number % 10 * decimal);
    decimal *= 10;
    number /= 10;
  }
  return components;
}

namespace roman_numerals {
std::string convert(const unsigned int& number) {
  std::stack<unsigned int> components(ComponentOf(number));

  std::string converted = "";

  while (!components.empty()) {
    unsigned int comp = components.top(), digit = comp, decimal = 1;

    while (digit / 10 != 0) {
      digit /= 10;
      decimal *= 10;
    }
    if (4 == digit % 5) {
      converted += kRomanianVersionOf.at(decimal);
      converted += kRomanianVersionOf.at(comp + decimal);
    } else if (digit >= 5) {
      converted += kRomanianVersionOf.at(5 * decimal);
      comp -= 5 * decimal;
      while (comp != 0) {
        converted += kRomanianVersionOf.at(decimal);
        comp -= decimal;
      }
    } else
      while (comp != 0) {
        converted += kRomanianVersionOf.at(decimal);
        comp -= decimal;
      }
    components.pop();
  }
  return converted;
}
}  // namespace roman_numerals
