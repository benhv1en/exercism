#include "atbash_cipher.h"

std::string Normalised(std::string str) {
  for (size_t i = 0; i < str.size(); ++i) {
    while ((' ' == str[i]) || (',' == str[i]) || ('.' == str[i]))
      str = str.substr(0, i) + str.substr(i + 1);
    if (('A' <= str[i]) && (str[i] <= 'Z')) str[i] += 'a' - 'A';
  }
  return str;
}

namespace atbash_cipher {

std::string encode(const std::string& plain) {
  std::string cipher(Normalised(plain));

  for (char& character : cipher)
    if ((character < '0') || (character > '9'))
      character = 'z' - (character - 'a');
  for (size_t i = 5; i < cipher.size(); i += 6)
    cipher = cipher.substr(0, i) + " " + cipher.substr(i);
  return cipher;
}

std::string decode(const std::string& cipher) {
  std::string plain(Normalised(cipher));
  for (char& character : plain)
    if ((character < '0') || (character > '9'))
      character = 'z' - (character - 'a');
  return plain;
}
}  // namespace atbash_cipher
