#include "vanilla_option.h"
#include "../utils/distributions.h"
#include "../utils/utils.h"
#include <cmath>

VanillaOption::VanillaOption(double &S_, double &K_, double &sigma_, double &r_,
                             double &T_)
    : S(S_), K(K_), sigma(sigma_), r(r_), T(T_) {}

VanillaOption::VanillaOption(const VanillaOption &rhs)
    : S(rhs.S), K(rhs.K), sigma(rhs.sigma), r(rhs.r), T(rhs.T) {};

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
