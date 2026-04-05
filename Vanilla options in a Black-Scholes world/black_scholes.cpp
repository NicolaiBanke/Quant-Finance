#ifndef __BLACK_SCHOLES_CPP
#define __BLACK_SCHOLES_CPP

#include "black_scholes.h"
#include "utils/distributions.h"
#include "utils/utils.h"
#include <cmath>

double forward_contract(double &S0, double &K, double &sigma, double &r, double &d, double &T)
{
    return exp(-d * T) * S0 - exp(-r * T) * K;
}

double call_option(double &S, double &K, double &sigma, double &r, double &T)
{
    double d_1 = d_j(1, T, r, K, S, sigma);
    double d_2 = d_j(2, T, r, K, S, sigma);

    return S * N(d_1) - K * exp(-r * T) * N(d_2);
}

double put_option(double &S, double &K, double &sigma, double &r, double &T)
{
    double d_1 = d_j(1, T, r, K, S, sigma);
    double d_2 = d_j(2, T, r, K, S, sigma);

    return -S * N(-d_1) + K * exp(-r * T) * N(-d_2);
}

double digital_call_option(double &S, double &K, double &sigma, double &r, double &T)
{
    double d_2 = d_j(2, T, r, K, S, sigma);

    return exp(-r * T) * N(d_2);
}

double digital_put_option(double &S, double &K, double &sigma, double &r, double &T)
{
    double d_2 = d_j(2, T, r, K, S, sigma);

    return exp(-r * T) * N(-d_2);
}

double zero_coupon_bond(double &r, double &T)
{
    return exp(-r * T);
}

#endif