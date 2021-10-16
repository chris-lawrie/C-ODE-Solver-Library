
#include "model.h"
#include "integrator-factory.h"
#include "integrator.h"
#include "euler.h"
#include "rk4.h"
#include "ab2.h"
#include <string>

using namespace std;

Integrator *IntegratorFactory::Create(string model, double time_step, const Model &system_model)

{
    Integrator *system_solver;
    if (model == "euler")
        system_solver = new Euler(time_step, system_model);
    else if (model == "ab2")
        system_solver = new AdamsBashforth2(time_step, system_model);
    else if (model == "rk4")
        system_solver = new RungeKutta4(time_step, system_model);
    else
        system_solver = NULL;

    return system_solver; 
}
