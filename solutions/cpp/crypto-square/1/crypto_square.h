#pragma once

#include <cmath>
#include <string>

namespace crypto_square {
class Text {
 private:
  std::string plain_;

 public:
  Text(const std::string& plain) : plain_(plain) {}
  std::string normalized_cipher_text();
};

Text cipher(const std::string&);
}  // namespace crypto_square
