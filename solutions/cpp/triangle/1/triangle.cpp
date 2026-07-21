#include <stdexcept>
#include "triangle.h"

namespace triangle {

bool MakeATriangle(const double& edge_1, const double& edge_2,
                   const double& edge_3) {
  return (edge_1 + edge_2 > edge_3) && (edge_1 + edge_3 > edge_2) &&
         (edge_3 + edge_2 > edge_1) && (edge_1 > 0) && (edge_2 > 0) &&
         (edge_3 > 0);
}

bool IsEquilateral(const double& edge_1, const double& edge_2,
                   const double& edge_3) {
  return ((edge_1 == edge_2) && (edge_1 == edge_3));
}

bool IsIsosceles(const double& edge_1, const double& edge_2,
                 const double& edge_3) {
  return ((edge_1 == edge_2) && (edge_1 != edge_3)) ||
         ((edge_1 == edge_3) && (edge_1 != edge_2)) ||
         ((edge_3 == edge_2) && (edge_1 != edge_3));
}

bool IsScalene(const double& edge_1, const double& edge_2,
               const double& edge_3) {
  return (edge_1 != edge_2) && (edge_2 != edge_3) && (edge_3 != edge_1);
}

flavor kind(const double& edge_1, const double& edge_2, const double& edge_3) {
    if (!MakeATriangle(edge_1, edge_2, edge_3)) throw std::domain_error("");
    if (IsEquilateral(edge_1, edge_2, edge_3)) return flavor::equilateral;
    if (IsIsosceles(edge_1, edge_2, edge_3))
      return flavor::isosceles;
    else
      return flavor::scalene;
}
}  // namespace triangle