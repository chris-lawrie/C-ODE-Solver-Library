#ifndef MODEL_FACTORY_H_
#define MODEL_FACTORY_H_

#include "model.h"
#include <string>
using namespace std;

class ModelFactory
{
public:
    static Model *Create(string model, double *mod_params); // static allows to later call the function on the whole ModelFactor class
                                                           // since it doesn't need any information from the instance varaibles (in this case we don't have any).
};

#endif