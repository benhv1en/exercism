#pragma once
#include <iomanip>
#include <string>
#include <sstream>

namespace date_independent {
class clock {
 private:
  int hour_, minutes_;
  static std::pair<int, int> Normalise(const int&, const int&);

 public:
  clock() {}
  clock(const int& hour, const int& minutes) : hour_(hour), minutes_(minutes) {}
  static clock at(const int&, const int&);
  clock plus(const int&);
  explicit operator std::string() const;
  int Hour();
  int Minute();
  bool operator==(const clock) const;
  bool operator!=(const clock) const;
};
}  // namespace date_independant
