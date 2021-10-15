// Header file for the RungeKutta4 method
#ifndef RungeKutta4_H_
#define RungeKutta4_H_

#include "integrator.h"
#include "model.h"

class RungeKutta4 : public Integrator
{
public:
  RungeKutta4(double dt, const Model &model); // constructor
  ~RungeKutta4();				              // destructor

  int Step(double t, double *x);
  
private:
  const double dt_; 		  // timestep
  const Model &model_;		  // functor to evaluate f(x,t)
  const int dimen_;		      // dimension of state x

  double *fx_;			// will point to temporary scratch
  double *temp_x;        // array to store old x values
  double *k1;
  double *k2;
  double *k3;
  double *k4;
};

#endif  
