#include "prime_factors.h"

long long NextPrimeAfter(long long number) {
  bool is_prime = false;
  while (!is_prime) {
    if (2 == number) return 3;
    if (3 == number) return 5;
    if (4 == number) return 5;
    if (5 == number) return 7;
    if ((0 == number % 2) && (number % 10 != 4))
      number += 1;
    else if (4 == number % 10)
      number += 3;
    else {
      if (3 == number % 10)
        number += 4;
      else
        number += 2;
    }

    is_prime = false;
    for (long long i = 2; i <= sqrt(number); ++i)
      if (number % i == 0)
        break;
      else
        is_prime = true;
  }
  return number;
}


namespace prime_factors {
std::vector<long long> of(long long number) {
  if (number <= 1) return {};

  std::vector<long long> primes;
  long long index = 2;
  while ((number != 1)) {
    if (0 == number % index) {
      primes.emplace_back(index);
      number /= index;
    } else
      index = NextPrimeAfter(index);
  }
  return primes;
}
}  // namespace prime_factors