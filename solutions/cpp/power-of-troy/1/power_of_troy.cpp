#include "power_of_troy.h"

namespace troy {
    
void give_new_artifact(human& man, const std::string& fact) {
    man.possession = std::make_unique<artifact>(fact);
}

void exchange_artifacts(std::unique_ptr<artifact>& fact_1,
                        std::unique_ptr<artifact>& fact_2) {
  fact_1.swap(fact_2);
}
    
void manifest_power(human& man, const std::string& pow) {
      man.own_power = std::make_shared<power>(pow);
}
    
void use_power(const human& man_1, human& man_2) {
  man_2.influenced_by = man_1.own_power;
}

long power_intensity(const human& man) { return man.own_power.use_count(); } 
    
}  // namespace troy