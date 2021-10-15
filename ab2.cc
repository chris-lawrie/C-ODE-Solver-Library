// What does this script need to do?
/* 
- define all the functions needed in the ab2 method?
*/

#include "ab2.h"
#include "model.h"
#include "rk4.h"
#include <cmath> // C++ way to get the C math library #include <math.h>

// Constructor for the Ab2 object (aka class)
// Ab2 objects should be initialized with a timestep and a Model
// Note that "model" has rhs and n defined in it.

// dimen_ == n (size of model)
// If a variable is constant in the header file - you have to define it / initialise it before the contructor
AdamsBashforth2::AdamsBashforth2(double dt, const Model &model)
    : dt_(dt), model_(model), dimen_(model.dimen()) // Initialization list
{
  // Constructor pre-allocates heap space for rhs() results
  fx_ = new double[dimen_];
  fx_old = new double[dimen_];
  prev_exists = false;
}

// Destructor housekeeping -- free space used for rhs() results
AdamsBashforth2::~AdamsBashforth2()
{
  delete[] fx_;
  delete[] fx_old;
}

// enter code to run RK4 method for first step
// currently just put in Euler method as place holder code
int AdamsBashforth2::run_RK4(double t, double *x)
{
  RungeKutta4 *rk4 = new RungeKutta4(dt_, model_);
  rk4->Step(t, x);
  delete rk4;
  return 0; // Successful exit
}

// Overwriting the mechanics of the Step function as defined in the
// euler.h header file - which extends the virtual step function in
// integrator.h

// add in prev exists
int AdamsBashforth2::Step(double t, double *x)
{
  model_.rhs(t, x, fx_);

  // Run RK4 for the first time step
  if (!prev_exists)
  {
    run_RK4(t, x); // Run RK4 for the first time step
    prev_exists = true;
  }

  // Run ab2 for all other steps
  else
  {
    model_.rhs(t, x, fx_);
    for (int i = 0; i < dimen_; ++i)
    {
      x[i] += dt_ * ((fx_[i]) * (3.0 / 2.0) - (fx_old[i]) / 2.0);
    }
  }

  // Update fx_old :)
  for (int i = 0; i < dimen_; ++i)
  {
    fx_old[i] = fx_[i];
  }

  return 0;
}