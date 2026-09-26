#pragma once
double forward_contract(const double &S0, const double &K, const double &r,
                        const double &T, const double &d = 0);

double zero_coupon_bond(const double &r, const double &T);
