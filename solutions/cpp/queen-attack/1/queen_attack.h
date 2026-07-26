#pragma once
#include <cmath>
#include <stdexcept>
#include <utility>

namespace queen_attack {
class chess_board {
 private:
  std::pair<int, int> white_, black_;

 public:
  chess_board(const std::pair<int, int>& white,
              const std::pair<int, int>& black)
      : white_(white), black_(black) {
    if ((0 > white.first) || (0 > black.first))
      throw std::domain_error("newly_placed_queen_must_have_positive_row");
    if ((7 < white.first) || (7 < black.first))
      throw std::domain_error("newly_placed_queen_must_have_row_on_board");
    if ((0 > white.second) || (0 > black.second))
      throw std::domain_error("newly_placed_queen_must_have_positive_column");
    if ((7 < white.second) || (7 < black.second))
      throw std::domain_error("newly_placed_queen_must_have_column_on_board");
    if ((white.first == black.first) && (white.second == black.second))
      throw std::domain_error("queen_positions_must_be_distinct");
  }

  std::pair<int, int> white() const;
  std::pair<int, int> black() const;
  bool can_attack() const;
};
}  // namespace queen_attack
