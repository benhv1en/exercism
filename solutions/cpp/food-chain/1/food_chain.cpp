#include "food_chain.h"

namespace food_chain {
std::string verse(const unsigned char& number) {
  if (1 == number)
    return "I know an old lady who swallowed a fly.\n"
           "I don't know why she swallowed the fly. Perhaps she'll die.\n";
  if (2 == number)
    return "I know an old lady who swallowed a spider.\n"
           "It wriggled and jiggled and tickled inside her.\n"
           "She swallowed the spider to catch the fly.\n"
           "I don't know why she swallowed the fly. Perhaps she'll die.\n";
  if (3 == number)
    return "I know an old lady who swallowed a bird.\n"
           "How absurd to swallow a bird!\n"
           "She swallowed the bird to catch the spider that wriggled and "
           "jiggled "
           "and tickled inside her.\n"
           "She swallowed the spider to catch the fly.\n"
           "I don't know why she swallowed the fly. Perhaps she'll die.\n";
  if (4 == number)
    return "I know an old lady who swallowed a cat.\n"
           "Imagine that, to swallow a cat!\n"
           "She swallowed the cat to catch the bird.\n"
           "She swallowed the bird to catch the spider that wriggled and "
           "jiggled "
           "and tickled inside her.\n"
           "She swallowed the spider to catch the fly.\n"
           "I don't know why she swallowed the fly. "
           "Perhaps she'll die.\n";
  if (5 == number)
    return "I know an old lady who swallowed a dog.\n"
           "What a hog, to swallow a dog!\n"
           "She swallowed the dog to catch the cat.\n"
           "She swallowed the cat to catch the bird.\n"
           "She swallowed the bird to catch the spider that wriggled and "
           "jiggled "
           "and tickled inside her.\n"
           "She swallowed the spider to catch the fly.\n"
           "I don't know why she swallowed the fly. "
           "Perhaps she'll die.\n";
  if (6 == number)
    return "I know an old lady who swallowed a goat.\n"
           "Just opened her throat and swallowed a goat!\n"
           "She swallowed the goat to catch the dog.\n"
           "She swallowed the dog to catch the cat.\n"
           "She swallowed the cat to catch the bird.\n"
           "She swallowed the bird to catch the spider that wriggled "
           "and jiggled "
           "and tickled inside her.\n"
           "She swallowed the spider to catch the fly.\n"
           "I don't know why she swallowed the fly. "
           "Perhaps she'll die.\n";
  if (7 == number)
    return "I know an old lady who swallowed a cow.\n"
           "I don't know how she swallowed a cow!\n"
           "She swallowed the cow to catch the goat.\n"
           "She swallowed the goat to catch the dog.\n"
           "She swallowed the dog to catch the cat.\n"
           "She swallowed the cat to catch the bird.\n"
           "She swallowed the bird to catch the spider that wriggled "
           "and jiggled "
           "and tickled inside her.\n"
           "She swallowed the spider to catch the fly.\n"
           "I don't know why she swallowed the fly. "
           "Perhaps she'll die.\n";
  if (8 == number)
    return "I know an old lady who swallowed a horse.\n"
           "She's dead, of course!\n";
    
  return "";
}

std::string verses(const unsigned char& start, const unsigned char& end) {
  std::string song = "";
  for (unsigned char i = start; i <= end; ++i) song += verse(i) + "\n";
  return song;
}

std::string sing() { return verses(1, 8); }
}  // namespace food_chain
