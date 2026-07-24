#include "nth_prime.h"

namespace nth_prime {
int nth(const int& order) {
  if (0 >= order) throw std::domain_error("");
  if (1 == order) return 2;
  if (2 == order) return 3;

  std::map<int, int> sieve;
  const int kNotVisited = -1, kCrossed = -2, kCeil = ceil(order * log2(order));

  for (int i = 2; i <= kCeil; ++i) sieve[i] = kNotVisited;
  int number_of_prime = 0;
  for (int i = 2; i <= kCeil; ++i) {
    if (sieve.at(i) == kNotVisited) {
      ++number_of_prime;
      sieve[i] = number_of_prime;
      for (int j = 2; j <= kCeil / i; ++j) sieve[j * i] = kCrossed;
    }
  }

  int return_prime = 0;
  for (std::map<int, int>::reverse_iterator sieved = sieve.rbegin();
       sieved != sieve.rend(); ++sieved)
    if (sieved->second == order) return_prime = sieved->first;
  return return_prime;
}
}  // namespace nth_prime
