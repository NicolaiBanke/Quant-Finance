#ifndef __UTILS_H
#define __UTILS_H

#include <vector>

double power_sum(const std::vector<double> &vec, const double &var);
double d_j(const int j, double &S, double &K, double &sigma, double &r,
           double &T);

#endif
