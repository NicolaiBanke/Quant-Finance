#include "../../include/quant_finance/domain/Option.h"

Option::Option(const double &S0_, const double &K_, const double &r_,
               const double &T_, const double &sigma_, const double &d_)
    : S0(S0_), K(K_), r(r_), T(T_), sigma(sigma_), d(d_) {};
