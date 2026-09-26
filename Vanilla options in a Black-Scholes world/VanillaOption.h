#pragma once
#include "../lib/Option.h"

class VanillaOption : public Option {
public:
  VanillaOption(const double &S, const double &K, const double &r,
                const double &T, const double &sigma);

  ~VanillaOption() override = default;

  double calc_call_price() override;
  double calc_put_price() override;
};
