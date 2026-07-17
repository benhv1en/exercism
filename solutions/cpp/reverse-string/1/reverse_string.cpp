#include "reverse_string.h"

namespace reverse_string {

// TODO: add your solution here
void Swap(char& c_1, char& c_2) {
  char temp = c_1;
  c_1 = c_2;
  c_2 = temp;
}
std::string reverse_string(std::string original) {
  std::string reversed = original;
  int i = 0, j = reversed.size() - 1;
  while (i < j) {
    Swap(reversed[i], reversed[j]);
    ++i;
    --j;
  }
  return reversed;
}
}  // namespace reverse_string
