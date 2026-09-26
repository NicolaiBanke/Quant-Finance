#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "./VanillaOption.h"
#include "./formulas.h"

double S0 = 10.0;
double K = 5.0;
double r = .01;
double T = 1.0;
double sigma = .1;
double d = .05;

VanillaOption vanilla_option(S0, K, r, T, sigma, d);

TEST_CASE("Put-Call Parity") {
  CHECK(vanilla_option.calc_call_price() - vanilla_option.calc_put_price() ==
        forward_contract(S0, K, r, T, d));
};
