#include "grains.h"

namespace grains {

unsigned long long square(const int& cell) { return 1ULL << (cell - 1); }

unsigned long long total() {
  unsigned long long sum = 0ULL;
  for (int i = 0; i < 64; ++i) sum += 1ULL << i;
  return sum;
}

}  // namespace grains
