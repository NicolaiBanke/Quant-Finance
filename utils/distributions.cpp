#ifndef __DISTRIBUTIONS_CPP
#define __DISTRIBUTIONS_CPP

#include <iostream>
#include <vector>
#include <cmath>

#include "distributions.h"
#include "utils.h"



// cumulative normal function
double N(const double& x)
{
    if (x > 0)
    {
        const double k = 1 / (1 + 0.2316419 * x);

        return 1 - 1 / sqrt(2 * M_PI) * exp(-x * x / 2) * k * (0.319381530
        + k * (-0.356563782
        + k * (1.781477937 
        + k * (-1.821255978 
        + 1.330274429 * k))));
    }
    else
    {
        return 1 - N(-x);
    }
}

// Inverse cumulative normal function computed with Moro algorithm
double N_1(const double& x)
{

    const std::vector<const double> a = {
        2.50662823884,
        -18.61500062529,
        41.39119773534,
        -25.44106049637};

    const std::vector<const double> b = {
        -8.47351093090,
        23.08336743743,
        21.06224101826,
        3.13082909833};

    const std::vector<const double> c = {
        0.3374754822726147,
        0.9761690190917186,
        0.1607979714918209,
        0.0276438810333863,
        0.0038405729373609,
        0.0003951896511919,
        0.0000321767881768,
        0.0000002888167364,
        0.0000003960315187};

    const double y = x - 0.5;

    if (abs(y) < 0.42)
    {
        const double r = pow(y, 2);

        return (y * power_sum(a, r)) / (r * power_sum(b, r) + 1.0);
    }
    else
    {
        double r;
        if (y < 0)
        {
            r = x;
        }
        else
        {
            r = 1 - x;
        }
        double s = log(-log(r));
        double t = power_sum(c, s);

        if (x > 0.5)
        {
            return t;
        }
        else
        {
            return -t;
        }
    }
}
#endif