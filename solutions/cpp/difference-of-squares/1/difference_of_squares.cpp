#include "difference_of_squares.h"

namespace difference_of_squares {
unsigned long long square_of_sum(const int& number) {
  unsigned long long sum = 0ULL;
  for (int i = 1; i <= number; ++i) sum += i;
  return sum * sum;
}

// 0ULL == 0x0000000000000000
// 0    == 0xffffffff00000000

    
unsigned long long sum_of_squares(const int& number) {
  if (0 == number) return 0ULL;
  if (1 == number) return 1ULL;
  unsigned long long square = 0ULL;
  for (int i = 1; i <= number; ++i) square += i * i;
  return square;
}

unsigned long long difference(const int& number) {
  return square_of_sum(number) - sum_of_squares(number);
}
}  // namespace difference_of_squares
