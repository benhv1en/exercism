#include "crypto_square.h"

namespace crypto_square {

Text cipher(const std::string& plain) { return *(new Text(plain)); }

std::string Text::normalized_cipher_text() {
  for (size_t i = 0; i < plain_.size(); ++i) {
    while (((' ' <= plain_[i]) && (plain_[i] <= '/')) ||
           ((':' <= plain_[i]) && (plain_[i] <= '@')) ||
           (('[' <= plain_[i]) && (plain_[i] <= '`')))
      plain_ = plain_.substr(0, i) + plain_.substr(i + 1);
    if (('A' <= plain_[i]) && (plain_[i] <= 'Z')) plain_[i] += 'a' - 'A';
  }

  size_t row = sqrt(plain_.size()), column = sqrt(plain_.size());

  while (row * column < plain_.size()) {
    if (row == column)
      ++column;
    else
      ++row;
  }

  std::string ciphered = "";

  size_t index = 0;
  for (size_t j = 0; j < column; ++j) {
    for (size_t i = index; i < row * column; i += column) {
      if (i >= plain_.size())
        ciphered += " ";
      else
        ciphered += plain_[i];
    }
    if (j < column - 1) ciphered += " ";
    ++index;
  }
  return ciphered;
}

}  // namespace crypto_square
