#include "doctor_data.h"
namespace heaven {

Vessel::Vessel(std::string name, int generation, star_map::System system)
    : name(name), generation(generation), current_system(system) {}

void Vessel::make_buster() { ++busters; }

bool Vessel::shoot_buster() {
  if (busters != 0) {
    --busters;
    return true;
  }
  return false;
}
std::string get_older_bob(Vessel vessel_1, Vessel vessel_2) {
  return vessel_1.generation < vessel_2.generation ? vessel_1.name
                                                   : vessel_2.name;
}
Vessel Vessel::replicate(std::string name) {
  Vessel replicated(name, ++generation, current_system);
  return replicated;
}

bool in_the_same_system(Vessel vessel_1, Vessel vessel_2) {
  return vessel_1.current_system == vessel_2.current_system;
}
}  // namespace heaven