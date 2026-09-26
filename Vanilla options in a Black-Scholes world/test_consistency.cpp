#pragma once
#include "../doctest.h"
#include "formulas.h"
#include "vanilla_option.h"

double S = 10;
double K = 5;
double sigma = .1;
double r = .01;
double d = .02;
double T = 1;

VanillaOption vanilla_option = VanillaOption(S, K, sigma, r, T);

TEST_CASE("Put-Call Parity") {
  CHECK(vanilla_option.calc_call_price() - vanilla_option.calc_put_price() ==
        forward_contract(T, r, d, K, S, sigma));
};
