double forward_contract(double &T, double &r, double &d, double &K, double &S,
                        double &sigma);
double call_option(double &S, double &K, double &sigma, double &r, double &T);
double put_option(double &S, double &K, double &sigma, double &r, double &T);
double digital_call_option(double &S, double &K, double &sigma, double &r,
                           double &T);
double digital_put_option(double &S, double &K, double &sigma, double &r,
                          double &T);
double zero_coupon_bond(double &r, double &T);
