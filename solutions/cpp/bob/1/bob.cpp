#include "bob.h"

bool IsAllCapital(const std::string& message) {
  for (const char& letter : message) {
    if ((',' == letter) || (' ' == letter) || ('.' == letter) ||
        ('!' == letter))
      continue;
    if (('a' <= letter) && (letter <= 'z')) return false;
  }
  return true;
}
bool IsEndedWithQuestionMark(const std::string& message) {
  return *(message.rbegin()) == '?';
}
bool IsHavingLetter(const std::string& message) {
  for (const char& character : message)
    if ((('A' <= character) && (character <= 'Z')) ||
        (('a' <= character) && (character <= 'z')))
      return true;
  return false;
}

std::string AfterDeletingSpaces(std::string str) {
  for (size_t i = 0; i < str.size(); ++i)
    while ((' ' == str[i]) || ('\t' == str[i]) || ('\n' == str[i]) ||
           ('\r' == str[i]))
      str = str.substr(0, i) + str.substr(i + 1);
  return str;
}

namespace bob {
std::string hey(const std::string& str) {
  std::string message = AfterDeletingSpaces(str);
  if ("" == message) return "Fine. Be that way!";
  if (IsHavingLetter(message)) {
    if (IsAllCapital(message)) {
      if (IsEndedWithQuestionMark(message))
        return "Calm down, I know what I'm doing!";
      else
        return "Whoa, chill out!";
    } else {
      if (IsEndedWithQuestionMark(message)) return "Sure.";
    }
  } else if (IsEndedWithQuestionMark(message))
    return "Sure.";
  return "Whatever.";
}
}  // namespace bob