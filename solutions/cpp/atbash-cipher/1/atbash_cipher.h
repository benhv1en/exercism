#pragma once

#include <string>

std::string Normalised(std::string);

namespace atbash_cipher {
std::string encode(const std::string&);
std::string decode(const std::string& cipher);
}  // namespace atbash_cipher
