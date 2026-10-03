#include <cmath>
#include <cstdlib>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"
#include "../src/VanillaOption.h"
#include "../src/formulas.h"
#include <algorithm>
#include <vector>

double S0;
double K;
double r;
double T;
double sigma;
double d;

TEST_CASE("Put-Call Parity") {
  S0 = 10.0;
  K = 5.0;
  r = .01;
  T = 1.0;
  sigma = .1;
  d = .05;

  VanillaOption vanilla_option(S0, K, r, T, sigma, d);

  CHECK(vanilla_option.calc_call_price() - vanilla_option.calc_put_price() ==
        forward_contract(S0, K, r, T, d));
};

TEST_CASE("Price of a call option should be monotone with strike") {
  S0 = 10.0;
  K = .01;
  r = .01;
  T = 1.0;
  sigma = .1;
  d = .05;

  auto is_monotone = [&]() -> bool {
    std::vector<bool> directions;
    for (int i = 1; i <= 1000; i++) {
      VanillaOption vanilla_option_1(S0, K * i, r, T, sigma, d);
      VanillaOption vanilla_option_0(S0, K * (i - 1), r, T, sigma, d);

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

TEST_CASE("Call price bounds") {
  // maybe choosing the parameters so that the gap between the bounds become
  // extremely narrow will provide a justifiable check
  auto is_within_bounds = []() {
    for (int i = 0; i < 1000; i++) {
      S0 = 1000.0 * (rand() / float(RAND_MAX));
      K = 1000.0 * (rand() / float(RAND_MAX));
      r = (rand() / float(RAND_MAX));
      T = 10.0 * (rand() / float(RAND_MAX));
      sigma = (rand() / float(RAND_MAX));
      d = (rand() / float(RAND_MAX));

      VanillaOption vanilla_option(S0, K, r, T, sigma, d);

      if (!(S0 * exp(-d * T) - K * exp(-r * T) -
                    vanilla_option.calc_call_price() <=
                pow(10, -6) &&
            S0 * exp(-d * T) - vanilla_option.calc_call_price() >=
                pow(10, -6))) {
        return false;
      };
    };
    return true;
  };
  CHECK(is_within_bounds());
}

TEST_CASE("Monotone increase with volatility") {
  S0 = 10.0;
  K = 5.0;
  r = .01;
  sigma = .001;
  T = 1.0;
  d = .05;

  auto is_monotone = [&]() -> bool {
    for (int i = 1; i <= 1000; i++) {
      VanillaOption vanilla_option_1(S0, K, r, T, sigma * i, d);
      VanillaOption vanilla_option_0(S0, K, r, T, sigma * (i - 1), d);

      if (vanilla_option_1.calc_call_price() -
              vanilla_option_0.calc_call_price() <=
          -pow(10, -6)) {
        return false;
      };
    };
    return true;
  };

  CHECK(is_monotone());
};

TEST_CASE("For d=0 call price increases with T") {
  S0 = 10.0;
  K = 5.0;
  r = .01;
  sigma = .1;
  T = .01;
  d = 0.00;

  auto is_monotone = [&]() -> bool {
    for (int i = 1; i <= 1000; i++) {
      VanillaOption vanilla_option_1(S0, K, r, T * i, sigma, d);
      VanillaOption vanilla_option_0(S0, K, r, T * (i - 1), sigma, d);

      if (vanilla_option_1.calc_call_price() -
              vanilla_option_0.calc_call_price() <=
          -pow(10, -6)) {
        return false;
      };
    };
    return true;
  };

  CHECK(is_monotone());
};
