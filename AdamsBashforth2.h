// Header file for the AdamsBashforth2 method. 
// Change to full name! 

#ifndef AdamsBashforth2_H_
#define AdamsBashforth2_H_


#include "integrator.h"

class Model;			// Forward declaration

class AdamsBashforth2 : public Integrator
{
public:
  AdamsBashforth2(double dt, const Model &model); // constructor
  ~AdamsBashforth2();				// destructor

  int Step(double t, double *x);
  
private:
  const double dt_; 		  // timestep
  const Model &model_;		// functor to evaluate f(x,t)
  const int dimen_;		    // dimension of state x

  double *fx_;			// will point to temporary scratch
				// space to hold f(x,t)
};

#endif  // AdamsBashforth2
