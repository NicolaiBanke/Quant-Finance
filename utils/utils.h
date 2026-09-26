#ifndef __UTILS_H
#define __UTILS_H

#include <vector>

double power_sum(const std::vector<double> &vec, const double &var);
double d_j(const int j, const double &S0, const double &K, const double &r,
           const double &T, const double &sigma, const double &d = 0);

#endif
