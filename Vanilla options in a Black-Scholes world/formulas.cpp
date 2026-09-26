#include "./formulas.h"
#include <cmath>

double forward_contract(const double &S0, const double &K, const double &sigma,
                        const double &r, const double &d, const double &T) {
  return exp(-d * T) * S0 - exp(-r * T) * K;
}
double zero_coupon_bond(const double &r, const double &T) {
  return exp(-r * T);
}
