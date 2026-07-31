#include "robot_name.h"

namespace robot_name {
std::string robot::name() const { return name_; }
void robot::reset() {
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
}  // namespace robot_name
