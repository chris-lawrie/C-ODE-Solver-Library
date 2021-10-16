#include "model-factory.h"
#include "model.h"
#include "ddo.h"
#include "lv.h"
#include <string>
using namespace std;

Model *ModelFactory::Create(string model, double *mod_params)
{
    Model *system_model = nullptr;
    if (model == "ddo")
        system_model = new DDOscillator(mod_params);
    else if (model == "lv")
        system_model = new LotkaVolterra(mod_params);
    // else
    //     system_model = NULL;
    return system_model;
}
