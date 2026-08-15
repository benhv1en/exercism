#pragma once

#include <stdexcept>
#include <string>

namespace phone_number {
class phone_number {
 private:
  std::string number_;

 public:
  phone_number(std::string number) {
    if (number.size() <= 9) throw std::domain_error("invalid_when_9_digits");

    size_t index = 0;
    bool accessible = true, dashed = false;
    while ((number.at(index) != '-') || (!dashed)) {
      ++index;
      if ('-' == number.at(index)) {
        dashed = true;
        ++index;
      }
      if (index == number.size() - 1) {
        accessible = false;
        break;
      }
    }
    if ((accessible) &&
        (('0' == number.at(index - 3)) || ('1' == number.at(index - 3))))
      throw std::domain_error("invalid_if_exchange_code_starts_with_0_or_1");

    index = 0;
    accessible = true;
    while (number.at(index) != '(') {
      ++index;
      if (index == number.size() - 2) {
        accessible = false;
        break;
      }
    }
    if ((accessible) &&
        (('0' == number.at(index + 1)) || ('1' == number.at(index + 1))))
      throw std::domain_error("invalid_if_area_code_starts_with_0_or_1");

    std::string normalised_number = number;
    for (size_t i = 0; i < normalised_number.size(); ++i)
      while (('(' == normalised_number[i]) || (')' == normalised_number[i]) ||
             (' ' == normalised_number[i]) || ('-' == normalised_number[i]) ||
             ('.' == normalised_number[i]))
        normalised_number =
            normalised_number.substr(0, i) + normalised_number.substr(i + 1);

    if ((11 == normalised_number.size()) && (normalised_number.at(0) != '1'))
      throw std::domain_error("invalid_when_11_digits_does_not_start_with_a_1");

    if ((11 == normalised_number.size()) && ('1' == normalised_number.at(0)))
      normalised_number = normalised_number.substr(1);

    if (('+' == normalised_number.at(0)) && ('1' == normalised_number.at(1)))
      normalised_number = normalised_number.substr(2);

    std::string area_code = normalised_number.substr(0, 3),
                exchange_code = normalised_number.substr(3, 3);

    for (const char& character : normalised_number) {
      if (('a' <= character) && (character <= 'z'))
        throw std::domain_error("invalid_with_letters");
      if (('@' == character) || (':' == character) || ('!' == character))
        throw std::domain_error("invalid_with_punctuation");
    }

    if (('0' == area_code.at(0)) || ('1' == area_code.at(0)))
      throw std::domain_error("invalid_if_area_code_starts_with_0_or_1");
    if (('0' == exchange_code.at(0)) || ('1' == exchange_code.at(0)))
      throw std::domain_error("invalid_if_exchange_code_starts_with_0_or_1");

    if (normalised_number.size() != 10)
      throw std::domain_error("invalid_when_more_than_11_digits");
    number_ = normalised_number;
  }

  std::string number();
  void SetNumber(const std::string&);
};
}  // namespace phone_number
