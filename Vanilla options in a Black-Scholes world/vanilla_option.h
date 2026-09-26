#pragma once
#include "../lib/option.h"

class VanillaOption {
private:
  double K;
  double r;
  double T;
  double S;
  double sigma;

public:
  // Constructor
  VanillaOption(double &S_, double &K_, double &sigma_, double &r_, double &T_);
  // Destructor
  ~VanillaOption();
  // Copy
  VanillaOption(const VanillaOption &rhs);

  double calc_call_price();
  double calc_put_price();
};
