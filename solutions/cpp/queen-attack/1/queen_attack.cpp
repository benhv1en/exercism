#include "queen_attack.h"

namespace queen_attack {

std::pair<int, int> chess_board::white() const { return white_; }

std::pair<int, int> chess_board::black() const { return black_; }

bool chess_board::can_attack() const {
  return (white_.first == black_.first) || (white_.second == black_.second) ||
         (abs(white_.first - black_.first) ==
          abs(white_.second - black_.second));
}
}  // namespace queen_attack
