#pragma once
#include <string>
#include <vector>
#include <map>

namespace grade_school {
void AlphabeticallySort(std::vector<std::string>&);
class school {
 private:
  std::map<int, std::vector<std::string>> roster_;

 public:
  school() { roster_.clear(); }
  std::map<int, std::vector<std::string>> roster() const;
  void add(const std::string&, const int&);
  std::vector<std::string> grade(const int&) const;
};
}  // namespace grade_school