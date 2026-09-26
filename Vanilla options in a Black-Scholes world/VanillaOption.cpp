#include "./VanillaOption.h"
#include "../lib/Option.h"
#include "../utils/distributions.h"
#include "../utils/utils.h"
#include <cmath>

VanillaOption::VanillaOption(const double &S_, const double &K_,
                             const double &r_, const double &T_,
                             const double &sigma_)
    : Option(S_, K_, r_, T_, sigma_) {};

double VanillaOption::calc_call_price() {
  double d_1 = d_j(1, S, K, sigma, r, T);
  double d_2 = d_j(2, S, K, sigma, r, T);

  return S * N(d_1) - K * exp(-r * T) * N(d_2);
}
double VanillaOption::calc_put_price() {
  double d_1 = d_j(1, S, K, sigma, r, T);
  double d_2 = d_j(2, S, K, sigma, r, T);

  return -S * N(-d_1) + K * exp(-r * T) * N(-d_2);
}
