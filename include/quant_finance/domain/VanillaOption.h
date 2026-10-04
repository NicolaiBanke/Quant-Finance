#pragma once
#include "./Option.h"

class VanillaOption : public Option {
private:
  double d_j(const int j, const double &S0, const double &K, const double &r,
             const double &T, const double &sigma, const double &d = 0);

public:
  VanillaOption(const double &S0, const double &K, const double &r,
                const double &T, const double &sigma, const double &d = 0);

  ~VanillaOption() override = default;

  double calc_call_price() override;
  double calc_put_price() override;
};
