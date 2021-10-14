// What does this script need to do?
/* 
- define all the functions needed in the ab2 method?
*/

#include "AdamsBashforth2.h"
#include "model.h"
#include <cmath>              // C++ way to get the C math library #include <math.h>


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
}

// Destructor housekeeping -- free space used for rhs() results
AdamsBashforth2::~AdamsBashforth2()
{
  delete [] fx_;
  delete [] fx_old; 
}

// enter code to run RK4 method for first step 
// currently just put in Euler method as place holder code 
int AdamsBashforth2::run_RK4(double t, double *x)
{
    model_.rhs(t, x, fx_);            // updating fx to be what we need for calculations 
    for (int i = 0; i < dimen_; ++i) 
    {                                 // (Needs updating to Rk4)
        x[i] += dt_ * fx_[i];         // Fwd Euler method *********************************************
        fx_old[i] = fx_[i];
    }
    return 0;    // Successful exit   
}


// Overwriting the mechanics of the Step function as defined in the 
// euler.h header file - which extends the virtual step function in 
// integrator.h 
int AdamsBashforth2::Step(double t, double *x)
{
  model_.rhs(t, x, fx_);
  
  // Run RK4 for the first time step
  if (t == 0)
  {
    run_RK4(t, x);                  // Run RK4 for the first time step
  }

  // Run ab2 for all other steps 
  if (t>0)
  {
    model_.rhs(t, x, fx_);
    for (int i = 0; i < dimen_; ++i)
    {
        x[i] += dt_*((fx_[i])*(3.0/2.0)  - (fx_old[i]/2.0));
        fx_old[i] = fx_[i];
    }
  }
  return 0;
}