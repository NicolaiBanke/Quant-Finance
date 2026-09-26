#include "./digital_option.h"
#include "../utils/distributions.h"
#include "../utils/utils.h"
#include <cmath>

double digital_call_option(double &S, double &K, double &sigma, double &r,
                           double &T) {
  double d_2 = d_j(2, S, K, sigma, r, T);

  return exp(-r * T) * N(d_2);
}
double digital_put_option(double &S, double &K, double &sigma, double &r,
                          double &T) {
  double d_2 = d_j(2, S, K, sigma, r, T);

  return exp(-r * T) * N(-d_2);
}
