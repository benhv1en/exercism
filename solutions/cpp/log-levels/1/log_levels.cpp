#include <string>

namespace log_line {
std::string message(std::string line) {
  std::string::iterator pointer(line.begin());
  do {
    ++pointer;
  } while (' ' != *pointer);
  return *(new std::string(pointer + 1, line.end()));
}

std::string log_level(std::string line) {
  std::string level = "";
  for (const char& character : line) {
    if ('[' == character)
      continue;
    else if (']' == character)
      break;
    else
      level += character;
  }
  return level;
}

std::string reformat(std::string line) {
    return message(line) + " (" + log_level(line) + ")";
}
}  // namespace log_line
