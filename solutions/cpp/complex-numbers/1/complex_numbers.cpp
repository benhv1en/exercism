#include "complex_numbers.h"

namespace complex_numbers {

double Complex::real() const { return real_; }

double Complex::imag() const { return imaginary_; }

Complex Complex::operator+(const Complex& other) const {
  return *(new Complex(real_ + other.real_, imaginary_ + other.imaginary_));
}

Complex Complex::operator-(const Complex& other) const {
  return (*this) + (*(new Complex(-other.real_, -other.imaginary_)));
}

Complex Complex::operator*(const Complex& other) const {
  return *(new Complex(real_ * other.real_ - imaginary_ * other.imaginary_,
                       real_ * other.imaginary_ + imaginary_ * other.real_));
}

Complex Complex::conj() const { return *(new Complex(real_, -imaginary_)); }

double Complex::abs() const {
  return sqrt(real_ * real_ + imaginary_ * imaginary_);
}

Complex Complex::operator/(const Complex& other) const {
  return ((*this) * other.conj()) / (other.abs() * other.abs());
}

Complex Complex::exp() const {
  return *(new Complex(expl(real_) * cos(imaginary_),
                       expl(real_) * sin(imaginary_)));
}

Complex operator+(const Complex& addent_1, const double& addent_2) {
  return *(new Complex(addent_1.real() + addent_2, addent_1.imag()));
}

Complex operator+(const double& addent_1, const Complex& addent_2) {
  return addent_2 + addent_1;
}

Complex operator-(const Complex& minuend, const double& subtrahend) {
  return minuend + (-subtrahend);
}

Complex operator-(const double& minuend, const Complex& subtrahend) {
  return *(new Complex(minuend, 0)) - subtrahend;
}

Complex operator*(const Complex& factor_1, const double& factor_2) {
  return *(new Complex(factor_1.real() * factor_2, factor_1.imag() * factor_2));
}

Complex operator*(const double& factor_1, const Complex& factor_2) {
  return factor_2 * factor_1;
}

Complex operator/(const Complex& dividend, const double& divisor) {
  return dividend * (1 / divisor);
}

Complex operator/(const double& dividend, const Complex& divisor) {
  return dividend * (divisor.conj() / (divisor.abs() * divisor.abs()));
}
}  // namespace complex_numbers
