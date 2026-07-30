#include "allergies.h"

bool AllergicPerson::is_allergic_to(const std::string& item) {
  for (const std::string& allergen : allergies_)
    if (item == allergen) return true;
  return false;
}

std::unordered_set<std::string> AllergicPerson::get_allergies() {
  return allergies_;
}

void AllergicPerson::set_allergies(
    const std::unordered_set<std::string>& allergies) {
  allergies_ = allergies;
}

namespace allergies {
AllergicPerson allergy_test(int point) {
  point %= 1 << 8;
  std::unordered_set<std::string> allergies;
  for (int i = kAllergenEquivalentTo.size() - 1; i >= 0; --i)
    if (point - (1 << i) >= 0) {
      allergies.insert(kAllergenEquivalentTo[i]);
      point -= (1 << i);
    }
  AllergicPerson allergic_person;
  allergic_person.set_allergies(allergies);
  return allergic_person;
}
}  // namespace allergies