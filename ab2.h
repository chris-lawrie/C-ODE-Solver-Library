// Header file for the ab2 method. 
// Change to full name! 

#ifndef ab2_H_
#define ab2_H_


#include "integrator.h"

class Model;			// Forward declaration

class ab2 : public Integrator
{
public:
  ab2(double dt, const Model &model); // constructor
  ~ab2();				// destructor

  int Step(double t, double *x);
  
private:
  const double dt_; 		// timestep
  const Model &model_;		// functor to evaluate f(x,t)
  const int dimen_;		// dimension of state x

  double *fx_;			// will point to temporary scratch
				// space to hold f(x,t)
};

#endif  // ab2
