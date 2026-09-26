#pragma once

class DigitalOption {
private:
  double K;
  double r;
  double T;
  double S;
  double sigma;

public:
  // Constructor
  DigitalOption(double &S_, double &K_, double &sigma_, double &r_, double &T_);
  // Destructor
  DigitalOption();
  // Copy
  DigitalOption(const DigitalOption &rhs);

  double calc_call_price();
  double calc_put_price();
};
double digital_call_option(double &S, double &K, double &sigma, double &r,
                           double &T);
