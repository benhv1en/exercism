#include "trinary.h"

namespace trinary {
unsigned int to_decimal(const std::string& trinary) {
  unsigned int converted = 0;
  for (size_t i = 0; i < trinary.size(); ++i) {
    if ((trinary.at(i) < '0') || (trinary.at(i) > '2')) {
      converted = 0;
      break;
    }
    converted += (trinary.at(i) - '0') * pow(3, trinary.size() - 1 - i);
  }
  return converted;
}
}  // namespace trinary
