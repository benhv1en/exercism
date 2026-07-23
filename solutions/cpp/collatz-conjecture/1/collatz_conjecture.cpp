#include "collatz_conjecture.h"

namespace collatz_conjecture {

int steps(int number) {
  int total_step = 0;
  if (0 >= number) throw std::domain_error("");
  if (1 == number) return 0;
  while (1 < number) {
    if (0 == number % 2)
      number /= 2;
    else
      number = number * 3 + 1;
    ++total_step;
  }
  return total_step;
}
}  // namespace collatz_conjecture
