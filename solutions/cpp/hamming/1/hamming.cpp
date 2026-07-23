#include "hamming.h"

namespace hamming {
int compute(const std::string& strand_1, const std::string& strand_2) {
  if (strand_1.size() != strand_2.size()) throw std::domain_error("");
  int hamming_distance = 0;
  for (size_t i = 0; i < strand_1.size(); ++i)
    if (strand_1[i] != strand_2[i]) ++hamming_distance;
  return hamming_distance;
}
}  // namespace hamming