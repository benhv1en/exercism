#include "sieve.h"

namespace sieve {
std::vector<int> primes(const int& max) {
  std::map<int, bool> sieve;
  std::vector<int> sieved;

  for (int i = 2; i <= max; ++i) sieve[i] = true;

  for (int i = 2; i <= max; ++i)
    if (sieve.at(i)) {
      sieved.emplace_back(i);
      for (int j = 2; j <= max / i; ++j) sieve[j * i] = false;
    }
  return sieved;
}
}  // namespace sieve