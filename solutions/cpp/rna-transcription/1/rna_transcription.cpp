#include "rna_transcription.h"

namespace rna_transcription {
char to_rna(const char& nucleotide) {
  if ('A' == nucleotide) return 'U';
  if ('T' == nucleotide) return 'A';
  if ('G' == nucleotide) return 'C';
  if ('C' == nucleotide) return 'G';
    return '\0';
}
std::string to_rna(const std::string& strand) {
  std::string return_strand = strand;
  for (char &letter : return_strand) letter = to_rna(letter);
  return return_strand;
}
}  // namespace rna_transcription