#include "raindrops.h"
#include <stack>

namespace raindrops {

std::string IntegerToString(int number) {
  std::stack<int> digits;
  while (number != 0) {
    digits.push(number % 10);
    number /= 10;
  }
  std::string number_string;
  while (!digits.empty()) {
    number_string.push_back(digits.top() + '0');
    digits.pop();
  }
  return number_string;
}

std::string convert(const int& number) {
  std::string result = "";
  if (0 == number % 3) result += "Pling";
  if (0 == number % 5) result += "Plang";
  if (0 == number % 7) result += "Plong";
  if ("" == result) result = IntegerToString(number);
  return result;
}
}  // namespace raindrops