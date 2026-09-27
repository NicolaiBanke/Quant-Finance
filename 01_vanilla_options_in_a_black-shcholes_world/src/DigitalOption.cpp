#include "./DigitalOption.h"
#include "../../utils/distributions.h"
#include "../../utils/utils.h"
#include <cmath>

DigitalOption::DigitalOption(const double &S0_, const double &K_,
                             const double &r_, const double &T_,
                             const double &sigma_, const double &d_)
    : Option(S0_, K_, r_, T_, sigma_, d_) {};

double DigitalOption::calc_call_price() {
  double d_2 = d_j(2, S0, K, r, T, sigma, d);

  return exp(-r * T) * N(d_2);
}
double DigitalOption::calc_put_price() {
  double d_2 = d_j(2, S0, K, r, T, sigma, d);

  return exp(-r * T) * N(-d_2);
}
