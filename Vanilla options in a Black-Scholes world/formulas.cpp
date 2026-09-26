#include "./formulas.h"
#include <cmath>

double forward_contract(double &S0, double &K, double &sigma, double &r,
                        double &d, double &T) {
  return exp(-d * T) * S0 - exp(-r * T) * K;
}
double zero_coupon_bond(double &r, double &T) { return exp(-r * T); }
