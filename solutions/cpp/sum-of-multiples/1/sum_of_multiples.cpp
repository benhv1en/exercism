#include "sum_of_multiples.h"

namespace sum_of_multiples {
int to(const std::vector<int>& base, const int& level) {
  std::set<int> multiples;
  for (const int& number : base)
    for (double i = 1; i < static_cast<double>(level) / static_cast<double>(number); ++i)
        multiples.insert(i * number);

  int sum = 0;
  for (const int& number : multiples) sum += number;
  return sum;
}
}  // namespace sum_of_multiples
