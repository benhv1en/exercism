#include "word_count.h"

bool IsOneLetter(const char& character) {
  return ('a' <= character) && (character <= 'z');
}

std::string AfterDeletingSpecialCharacters(std::string sentence) {
  for (size_t i = 0; i < sentence.size(); ++i) {
    while (((('!' <= sentence.at(i)) && (sentence.at(i) <= '/')) ||
            ((':' <= sentence.at(i)) && (sentence.at(i) <= '@')) ||
            (('[' <= sentence.at(i)) && (sentence.at(i) <= '`'))) &&
           (sentence.at(i) != '\''))
      sentence = sentence.substr(0, i) + ' ' + sentence.substr(i + 1);
    if ((0 == i)) {
      if ('\'' == sentence.at(i)) sentence = sentence.substr(1);
    } else if (sentence.size() - 1 == i) {
      if ('\'' == sentence.at(i))
        sentence = sentence.substr(0, sentence.size() - 1);
    } else if (('\'' == sentence.at(i)) &&
               ((!IsOneLetter(sentence.at(i - 1))) ||
                (!IsOneLetter(sentence.at(i + 1)))))
      sentence = sentence.substr(0, i) + ' ' + sentence.substr(i + 1);
    if ((i <= sentence.size() - 1) &&
        (('\n' == sentence.at(i)) || ('\t' == sentence.at(i))))
      sentence[i] = ' ';
  }
  return sentence;
}

std::string AfterNormalising(std::string sentence) {
  for (char& character : sentence)
    if (('A' <= character) && (character <= 'Z')) character += 'a' - 'A';
  return sentence;
}

namespace word_count {
std::map<std::string, int> words(const std::string& sentence) {
  std::map<std::string, int> word_count_of;
  std::string lexicons =
      AfterDeletingSpecialCharacters(AfterNormalising(sentence));
  for (size_t i = 0; i < lexicons.size(); ++i) {
    if (' ' == lexicons.at(i)) continue;
    size_t j = i;
    while (j < lexicons.size() - 1) {
      if (' ' == lexicons.at(j + 1)) break;
      if ('\0' == lexicons.at(j + 1)) break;
      ++j;
    }
    ++word_count_of[lexicons.substr(i, j - i + 1)];
    i = j + 1;
  }
  return word_count_of;
}
}  // namespace word_count