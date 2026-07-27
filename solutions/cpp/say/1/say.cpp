#include "say.h"

std::string SayThreeDigits(long number) {
if (number < 0)
    throw std::domain_error("The number has to be greater than or equal to 0");
  if (number > 999)
    throw std::domain_error("The number has to be less than or equal to 999");

  std::string say = "";

  long hundred = number / 100;
  if (hundred != 0) say += kSayingNumbers.at(hundred) + " hundred";
  number %= 100;

  long ten = number / 10;
  if (ten != 0) {
    if ((ten >= 6) && (ten != 8)) {
      if (hundred != 0) say += " ";
      say += kSayingNumbers.at(ten) + "ty";
      int unit = number % 10;
      if (unit != 0) say += "-" + kSayingNumbers.at(unit);
    } else if (((2 <= ten) && (ten <= 5)) || (8 == ten)) {
      if (hundred != 0) say += " ";
      say += kSayingNumbers.at(ten * 10);
      int unit = number % 10;
      if (unit != 0) say += "-" + kSayingNumbers.at(unit);
    } else if ((14 == number) || (16 == number) || (17 == number) ||
               (19 == number)) {
      if (hundred != 0) say += " ";
      say += kSayingNumbers.at(number - 10) + "teen";
      return say;
    } else {
      if (hundred != 0) say += " ";
      say += kSayingNumbers.at(number);
      return say;
    }
  } else {
    int unit = number % 10;
    if (unit != 0) {
      if (hundred != 0)
        say += " and " + kSayingNumbers.at(number % 10);
      else
        say += kSayingNumbers.at(unit);
    } else if (0 == hundred)
      say += kSayingNumbers.at(unit);
  }
  return say;
}

namespace say {
std::string in_english(long number) {
  if (0 == number) return "zero";
  if (number >= 1'000'000'000'000) throw std::domain_error("Out of range");
  std::vector<long> classes;
  for (long i = 0; i < 4; ++i) {
    classes.push_back(number % 1000);
    number /= 1000;
  }
  std::string said = "";
  if (classes[3] != 0) {
    said += SayThreeDigits(classes[3]) + " billion";
    if ((classes[2] != 0) || (classes[1] != 0) || (classes[0] != 0))
      said += " ";
  }
  if (classes[2] != 0) {
    said += SayThreeDigits(classes[2]) + " million";
    if ((classes[1] != 0) || (classes[0] != 0)) said += " ";
  }
  if (classes[1] != 0) {
    said += SayThreeDigits(classes[1]) + " thousand";
    if (classes[0] != 0) said += " ";
  }
  if (classes[0] != 0) said += SayThreeDigits(classes[0]);
  return said;
}
}  // namespace say
