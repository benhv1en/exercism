#pragma once
#include <iostream>
#include <string>
#include <unordered_set>

#ifndef UPPER
#define UPPER (rand() % 26 + 65)
#endif

#ifndef DIGIT
#define DIGIT (rand() % 10 + 48)
#endif

static std::unordered_set<std::string> named_robots;

namespace robot_name {
class robot {
 private:
  std::string name_;

 public:
  robot() {
    for (;;) {
      name_.clear();
      name_ += UPPER;
      name_ += UPPER;
      name_ += DIGIT;
      name_ += DIGIT;
      name_ += DIGIT;
      if (named_robots.find(name_) == named_robots.end()) {
        named_robots.insert(name_);
        break;
      }
    }
  }

  std::string name() const;
  void reset();
};
}  // namespace robot_name