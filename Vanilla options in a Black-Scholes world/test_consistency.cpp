#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "./VanillaOption.h"
#include "./formulas.h"

const double S = 10.0;
const double K = 5.0;
const double sigma = .1;
const double r = .01;
const double d = .00;
const double T = 1.0;

VanillaOption vanilla_option(S, K, r, T, sigma);

TEST_CASE("Put-Call Parity") {
  CHECK(vanilla_option.calc_call_price() - vanilla_option.calc_put_price() ==
        forward_contract(S, K, r, d, T, sigma));
};
