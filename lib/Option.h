#pragma once

class Option {
public:
  double S;
  double K;
  double r;
  double T;
  double sigma;

  // Constructor
  Option(const double &S, const double &K, const double &r, const double &T,
         const double &sigma);
  // Copy constructor
  Option(const Option &rhs);
  // Destructor
  virtual ~Option() = default;

  virtual double calc_call_price() = 0;
  virtual double calc_put_price() = 0;
};
