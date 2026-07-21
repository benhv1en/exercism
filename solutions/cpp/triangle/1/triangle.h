#pragma once

namespace triangle {
enum class flavor { equilateral, isosceles, scalene, none };
bool MakeATriangle(const double&, const double&, const double&);
bool IsEquilateral(const double&, const double&, const double&);
bool IsIsosceles(const double&, const double&, const double&);
bool IsScalene(const double&, const double&, const double&);
flavor kind(const double&, const double&, const double&);
}  // namespace triangle