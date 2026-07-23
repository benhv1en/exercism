#pragma once
#include <map>
#include <string>
#include <stdexcept>

namespace nucleotide_count {
bool IsNucleotide(const char&);
std::map<char, int> count(const std::string&);
}  // namespace nucleotide_count
