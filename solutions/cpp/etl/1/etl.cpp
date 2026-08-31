#include "etl.h"

namespace etl {
std::map<char, int> transform(std::map<int, std::vector<char>> letters_worth) {
  std::map<char, int> point_of;
  for (std::pair<int, std::vector<char>> lw : letters_worth)
    for (char& letter : lw.second) point_of[letter + 'a' - 'A'] = lw.first;
  return point_of;
}
}  // namespace etl
