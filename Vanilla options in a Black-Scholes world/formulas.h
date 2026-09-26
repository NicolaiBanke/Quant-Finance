#pragma once
double forward_contract(const double &S, const double &K, const double &r,
                        const double &d, const double &T, const double &sigma);

double zero_coupon_bond(const double &r, const double &T);
