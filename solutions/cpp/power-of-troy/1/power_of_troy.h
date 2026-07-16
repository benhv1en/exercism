#pragma once

#include <string>
#include <memory>

namespace troy {

struct artifact {
    // constructors needed (until C++20)
    artifact(std::string name) : name(name) {}
    std::string name;
};

struct power {
    // constructors needed (until C++20)
    power(std::string effect) : effect(effect) {}
    std::string effect;
};

struct human {
  std::unique_ptr<artifact> possession;
  std::shared_ptr<power> own_power, influenced_by;
};

void give_new_artifact(human& man, const std::string& fact);
void exchange_artifacts(std::unique_ptr<artifact>& fact_1,
                        std::unique_ptr<artifact>& fact_2);
void manifest_power(human& man, const std::string& pow);
void use_power(const human& man_1, human& man_2);
long power_intensity(const human& man);
}  // namespace troy
