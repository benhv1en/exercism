#include "series.h"

namespace series {
std::vector<std::string> slice(const std::string& digits,
                               const size_t& length) {
  if (length > digits.size())
    throw std::domain_error("slice_length_is_too_large");
  if (length <= 0)
    throw std::domain_error("slice_length_cannot_be_zero_or_negative");
  if (0 == digits.size()) throw std::domain_error("empty_series_is_invalid");

  std::vector<std::string> substring;
  for (size_t i = 0; i < digits.size() - length + 1; ++i)
    substring.emplace_back(digits.substr(i, length));
  return substring;
}
}  // namespace series
