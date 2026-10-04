#include "../../include/quant_finance/domain/VanillaOption.h"
#include "../../include/quant_finance/core/distributions.h"
#include "../../include/quant_finance/domain/Option.h"
#include <cmath>

VanillaOption::VanillaOption(const double &S0_, const double &K_,
                             const double &r_, const double &T_,
                             const double &sigma_, const double &d_)
    : Option(S0_, K_, r_, T_, sigma_, d_) {};

double VanillaOption::calc_call_price() {
  double d_1 = d_j(1, S0, K, r, T, sigma, d);
  double d_2 = d_j(2, S0, K, r, T, sigma, d);

  return S0 * exp(-d * T) * N(d_1) - K * exp(-r * T) * N(d_2);
}
double VanillaOption::calc_put_price() {
  double d_1 = d_j(1, S0, K, r, T, sigma, d);
  double d_2 = d_j(2, S0, K, r, T, sigma, d);

  return -S0 * exp(-d * T) * N(-d_1) + K * exp(-r * T) * N(-d_2);
}

double VanillaOption::d_j(const int j, const double &S0, const double &K,
                          const double &r, const double &T, const double &sigma,
                          const double &d) {
  return (log(S0 / K) +
          (r - d + pow((-1), j - 1) * (1.0 / 2) * pow(sigma, 2)) * T) /
         (sigma * sqrt(T));
}
