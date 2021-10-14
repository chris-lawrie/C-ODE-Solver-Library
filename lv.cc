// Body file for LV method
#include "lv.h"

#include <cmath>  // C++ way to get the C math library #include <math.h>

using namespace std;  // not sure what this does?

LotkaVolterra::LotkaVolterra(double *params) : 

    // Define params for the system:
    alpha(params[0]),     // alpha = birth rate of rabbits 
    beta(params[1]),      // beta  = death rate of rabbits (due to predataion by foxes)
    gamma(params[2]),     // gamma = birth rate of foxes (per rabit consumed) 
    delta(params[3])      // delta = death rate of foxes

{}				          // Empty constructor body

// Empty destructor (there are no extra memory/objects to free/delete)
LotkaVolterra::~LotkaVolterra() {}

// rhs()
// where:
//     x[0] = R, fx[0] = R_dot 
//     x[1] = F, fx[1] = F_dot

// The Lotka-Volterra System is as follows:
//   R_dot = (alpha * R) - (beta * R * F)
//   F_dot = (gamma * R * F) - (delta * F)

int LotkaVolterra::rhs(double t, const double *x, double *fx) const
{
  fx[0] = (alpha * x[0]) - (beta * x[0] * x[1]);
  fx[1] = (gamma * x[0] * x[1]) - (delta * x[1]);
  return 0;
}
