#pragma once
#include <array>
#include <string>
#include <unordered_set>

class AllergicPerson {
 private:
  std::unordered_set<std::string> allergies_;

 public:
  AllergicPerson() {}
  bool is_allergic_to(const std::string&);
  std::unordered_set<std::string> get_allergies();
  void set_allergies(const std::unordered_set<std::string>& allergies);
};

const std::array<std::string, 8> kAllergenEquivalentTo = {
    "eggs",     "peanuts",   "shellfish", "strawberries",
    "tomatoes", "chocolate", "pollen",    "cats"};

namespace allergies {
AllergicPerson allergy_test(int);
}