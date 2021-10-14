#include "rk4.h"
#include "model.h"

RungeKutta4::RungeKutta4(double dt, const Model &model)
  : dt_(dt), model_(model), dimen_(model.dimen()) // Initialization List
{
  // Constructor pre-allocates heap space for rhs() results
  fx_ = new double[dimen_];
  temp_x = new double[dimen_];
  k1 = new double[dimen_];
  k2 = new double[dimen_];
  k3 = new double[dimen_];
  k4 = new double[dimen_];


}

// Destructor housekeeping -- free space used for rhs() results
RungeKutta4::~RungeKutta4()
{
  delete [] fx_;
  delete [] temp_x;
  delete [] k1;
  delete [] k2;
  delete [] k3;
  delete [] k4;
}

// Overwriting the mechanics of the Step function
int RungeKutta4::Step(double t, double *x)
{
  // K1 
  model_.rhs(t, x, fx_);
  for (int i = 0; i < dimen_; ++i) k1[i] += dt_ * fx_[i];        // calculate k1
  for (int i = 0; i < dimen_; ++i) temp_x[i] = x[i] + k1[i]/2;   //define temp_x for k1

  // K2
  model_.rhs(t + (dt_/2.0), temp_x, fx_);
  for (int i = 0; i < dimen_; ++i) k2[i] += dt_ * fx_[i];        // calculate k2
  for (int i = 0; i < dimen_; ++i) temp_x[i] = x[i] + k2[i]/2;   //define temp_x for k2

  // K3
  model_.rhs(t + (dt_/2.0), temp_x, fx_);
  for (int i = 0; i < dimen_; ++i) k3[i] += dt_ * fx_[i];        // calculate k3
  for (int i = 0; i < dimen_; ++i) temp_x[i] = x[i] + k3[i];     //define temp_x for k3

  // K4
  model_.rhs(t + dt_, temp_x, fx_);
  for (int i = 0; i < dimen_; ++i) k4[i] += dt_ * fx_[i];        // calculate k4


  // Finish the calculation (i.e. calculate the next step of x)
  // x_(i+1) = x_i + ((k1 + k4)/6 + (k2 + k3)/3)*dt
  for (int i = 0; i < dimen_; i++) 
  {
      x[i] += ((k1[i] + k4[i])/6.0 + (k2[i] + k3[i])/3.0)*dt_;
  }

  return 0;
}