#ifndef __UTILS_CPP
#define __UTILS_CPP

#include <vector>
#include <cmath>

double power_sum(const std::vector<const double>& vec, const double& var)
{

    double sum = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        sum += vec[i] * pow(var, i);
    }

    return sum;
}

#endif