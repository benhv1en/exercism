#pragma once
#include <vector>
#include <string>
namespace lasagna_master {

struct amount {
    int noodles;
    double sauce;
};
int preparationTime(const std::vector<std::string>& layers,
                    int time_each = 2);
amount quantities(std::vector<std::string> layers);
void addSecretIngredient(std::vector<std::string>& own_recipe,
                         const std::vector<std::string>& his_recipe);
std::vector<double> scaleRecipe(const std::vector<double>& amounts,
                                const int& portion);
void addSecretIngredient(std::vector<std::string>& own_recipe,
                         const std::string& secret_ingredient);

}  // namespace lasagna_master
