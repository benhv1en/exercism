#include "lasagna_master.h"

namespace lasagna_master {
int preparationTime(const std::vector<std::string>& layers,
                    int time_each) {
  return static_cast<int>(layers.size() * time_each);
}


amount quantities(std::vector<std::string> layers) {
  int noodle = 0;
  double sauce = 0;
  for (const std::string& layer : layers) {
    if ("noodles" == layer) {
      noodle += 50;
    } else if ("sauce" == layer) {
      sauce += 0.2;
    }
  }
  return amount{noodle, sauce};
}
void addSecretIngredient(std::vector<std::string>& own_recipe,
                         const std::vector<std::string>& his_recipe) {
  own_recipe[own_recipe.size() - 1] = his_recipe[his_recipe.size() - 1];
}

std::vector<double> scaleRecipe(const std::vector<double>& amounts,
                                const int& portion) {
  std::vector<double> return_amounts = amounts;
  for (double& amount : return_amounts) amount *= portion / 2.0;
  return return_amounts;
}

void addSecretIngredient(std::vector<std::string>& own_recipe,
                         const std::string& secret_ingredient) {
  own_recipe.pop_back();
  own_recipe.push_back(secret_ingredient);
}

// TODO: add your solution here

}  // namespace lasagna_master
