// Header file for the AdamsBashforth2 method

#ifndef AdamsBashforth2_H_
#define AdamsBashforth2_H_

#include "integrator.h"
#include "model.h"

class AdamsBashforth2 : public Integrator
{
public:
  AdamsBashforth2(double dt, const Model &model); // constructor
  ~AdamsBashforth2();				                      // destructor

  int run_RK4(double t, double *x);
  int Step(double t, double *x);

  
private:
  const double dt_; 		  // timestep
  const Model &model_;		// functor to evaluate f(x,t)
  const int dimen_;		    // dimension of state x

  double *fx_;			// will point to temporary scratch
  double *fx_old;   // will point to temporary scratch
  bool prev_exists; 
};

#endif  // AdamsBashforth2
