#ifndef INTEGRATOR_FACTORY_H_
#define INTEGRATOR_FACTORY_H_

#include "model.h"
#include "integrator.h"
#include "euler.h"
#include "rk4.h"
#include "ab2.h"
#include <string>
using namespace std;

class IntegratorFactory
{
public:
    static Integrator *Create(string model, double time_step, const Model &system_model);
};

#endif