#pragma once

class Option {
public:
  double S0;
  double K;
  double r;
  double T;
  double sigma;
  double d;
  // Constructor
  Option(const double &S0, const double &K, const double &r, const double &T,
         const double &sigma, const double &d = 0);
  // Copy constructor
  Option(const Option &rhs);
  // Destructor
  virtual ~Option() = default;

  virtual double calc_call_price() = 0;
  virtual double calc_put_price() = 0;
};
