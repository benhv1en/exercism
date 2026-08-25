#pragma once

#include <map>
#include <string>

std::string AfterDeletingSpecialCharacters(std::string);

std::string AfterNormalising(std::string);

bool IsOneLetter(const char&);

namespace word_count {
std::map<std::string, int> words(const std::string&);
}
