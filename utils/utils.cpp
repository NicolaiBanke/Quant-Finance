#ifndef __UTILS_CPP
#define __UTILS_CPP

#include <cmath>
#include <vector>

double power_sum(const std::vector<double> &vec, const double &var) {

  double sum = 0;
  for (int i = 0; i < vec.size(); i++) {
    sum += vec[i] * pow(var, i);
  }

  return sum;
}

double d_j(const int j, const double &S0, const double &K, const double &r,
           const double &T, const double &sigma, const double &d) {
  return (log(S0 / K) +
          (r - d + pow((-1), j - 1) * (1.0 / 2) * pow(sigma, 2)) * T) /
         (sigma * sqrt(T));
}

#endif
