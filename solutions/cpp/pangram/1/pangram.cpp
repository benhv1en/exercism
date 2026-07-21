#include "pangram.h"

namespace pangram {
bool is_pangram(const std::string& sentence) {
  int number_of_character = 0;
  for (char letter = 'A'; letter <= 'Z'; ++letter)
    for (const char& character : sentence)
      if ((character == letter) || (character == letter + 32)) {
        ++number_of_character;
        break;
      }
  return number_of_character == 26;
}
}  // namespace pangram
