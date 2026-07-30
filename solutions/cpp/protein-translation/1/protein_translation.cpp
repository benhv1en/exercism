#include "protein_translation.h"

namespace protein_translation {
std::vector<std::string> proteins(const std::string& strand) {
  std::vector<std::string> translated;
  for (size_t i = 0; i < strand.size(); i += 3) {
    std::string codon(strand.substr(i, 3));
    if (kAminoAcidTranslatedFrom.at(codon) == "STOP")
      break;
    else
      translated.push_back(kAminoAcidTranslatedFrom.at(codon));
  }
  return translated;
}
}  // namespace protein_transaction
