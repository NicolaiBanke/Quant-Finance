#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"
#include "../src/VanillaOption.h"
#include "../src/formulas.h"
#include <algorithm>
#include <vector>

TEST_CASE("Put-Call Parity") {
  double S0 = 10.0;
  double K = 5.0;
  double r = .01;
  double T = 1.0;
  double sigma = .1;
  double d = .05;

  VanillaOption vanilla_option(S0, K, r, T, sigma, d);

  CHECK(vanilla_option.calc_call_price() - vanilla_option.calc_put_price() ==
        forward_contract(S0, K, r, T, d));
};

TEST_CASE("Price of a call option should be monotone with strike") {
  double S0 = 10.0;
  double r = .01;
  double T = 1.0;
  double sigma = .1;
  double d = .05;

  auto is_monotone = [=]() -> bool {
    std::vector<bool> directions;
    for (int i = 1; i <= 1000; i++) {
      VanillaOption vanilla_option_1(S0, (S0 / 1000) * i, r, T, sigma, d);
      VanillaOption vanilla_option_0(S0, (S0 / 1000) * (i - 1), r, T, sigma, d);

      directions.push_back(vanilla_option_1.calc_call_price() <
                           vanilla_option_0.calc_call_price());
    };
    return directions.empty() ||
           std::all_of(
               directions.begin() + 1, directions.end(),
               [&directions](bool x) -> bool { return x == directions[0]; });
  };

  CHECK(is_monotone());
}
