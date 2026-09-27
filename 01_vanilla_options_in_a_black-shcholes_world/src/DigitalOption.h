#pragma once
#include "../../lib/Option.h"
#include "./DigitalOption.h"

class DigitalOption : public Option {
public:
  DigitalOption(const double &S0, const double &K, const double &r,
                const double &T, const double &sigma, const double &d = 0);

  ~DigitalOption() override = default;

  double calc_call_price() override;
  double calc_put_price() override;
};
