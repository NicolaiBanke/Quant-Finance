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

double d_j(const int j, double &S, double &K, double &sigma, double &r,
           double &T) {
  return (log(S / K) + (r + pow((-1), j - 1) * (1.0 / 2) * pow(sigma, 2)) * T) /
         (sigma * sqrt(T));
}

#endif
