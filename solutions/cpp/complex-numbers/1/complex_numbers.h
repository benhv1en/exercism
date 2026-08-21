#pragma once

#include <cmath>

namespace complex_numbers {

class Complex {
 private:
  double real_, imaginary_;

 public:
  Complex(const double& real, const double& imaginary)
      : real_(real), imaginary_(imaginary) {}

  double real() const;
  double imag() const;
  Complex operator+(const Complex&) const;
  Complex operator-(const Complex&) const;
  Complex operator*(const Complex&) const;
  double abs() const;
  Complex conj() const;
  Complex operator/(const Complex&) const;
  Complex exp() const;
};
Complex operator+(const Complex&, const double&);
Complex operator+(const double&, const Complex&);
Complex operator-(const Complex&, const double&);
Complex operator-(const double&, const Complex&);
Complex operator*(const Complex&, const double&);
Complex operator*(const double&, const Complex&);
Complex operator/(const Complex&, const double&);
Complex operator/(const double&, const Complex&);
}  // namespace complex_numbers