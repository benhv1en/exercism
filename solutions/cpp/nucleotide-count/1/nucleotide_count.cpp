#include "nucleotide_count.h"

namespace nucleotide_count {

bool IsNucleotide(const char& letter) {
  return ('A' == letter) || ('T' == letter) || ('G' == letter) ||
         ('C' == letter);
}
std::map<char, int> count(const std::string& strand) {
  std::map<char, int> counted;
  for (char letter = 'A'; letter <= 'Z'; ++letter)
    if (IsNucleotide(letter)) counted[letter] = 0;
  for (const char& nucleotide : strand)
    if (!IsNucleotide(nucleotide))
      throw std::invalid_argument("");
    else
      ++counted[nucleotide];
  return counted;
}
}  // namespace nucleotide_count
