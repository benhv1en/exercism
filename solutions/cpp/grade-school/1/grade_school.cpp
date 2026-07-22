#include "grade_school.h"

namespace grade_school {
std::map<int, std::vector<std::string>> school::roster() const {
  return roster_;
}
void AlphabeticallySort(std::vector<std::string>& list) {
  for (size_t i = 0; i < list.size(); ++i)
    for (size_t j = 0; j < list.size() - i - 1; ++j)
      if (list[j][0] >= list[j + 1][0]) std::swap(list[j], list[j + 1]);
}
void school::add(const std::string& name, const int& grade) {
  roster_[grade].push_back(name);
  AlphabeticallySort(roster_[grade]);
}
std::vector<std::string> school::grade(const int& grade) const {
  if (roster_.find(grade) == roster_.end()) return std::vector<std::string>();
  return roster_.at(grade);
}
}  // namespace grade_school