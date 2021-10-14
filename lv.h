// Header file for LV method 
#ifndef LV_H_
#define LV_H_

#include "model.h"    

// Lotka-Volterra System:
//   R_dot = (alpha * R) - (beta * R * F)
//   F_dot = (gamma * R * F) - (delta * F)
class LotkaVolterra : public Model   // DDO inherits from model (rewrites the virtual functions)
{
public:
  // Constructor (initialize with params)
  //
  // `params[]` should be an array of length 4, holding the following per capita parameters
  //    alpha = birth rate of rabbits 
  //    beta  = death rate of rabbits (due to predataion by foxes)
  //    gamma = birth rate of foxes (per rabit consumed) 
  //    delta = death rate of foxes
  LotkaVolterra(double *params);
  ~LotkaVolterra();
  
  int rhs(double t, const double *x, double *fx) const;

  // Functions *defined* in the header are automatically `inline`-d --
  // `dimen() is so simple that we want to help the compiler figure
  // out that it could (should?)  inline it
  int dimen() const
  {
    return dimen_;
  }

private:
  // Parameters for the system
  const double alpha;
  const double beta;
  const double gamma;
  const double delta;

  // Dimension of state (`static` --> shared by all DDO instances)
  static const int dimen_ = 2;
};

#endif  // DDO_H_
