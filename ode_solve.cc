// General driver code for a given choice of ODE (eg. ddo, LV2)
// and a given choice of solver (Euler, ddo, ab2)

// Include some Standard Library packages
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// Include the models header files
#include "model.h"  // This is the parent for ddo.h and lv.h
#include "ddo.h"
#include "lv.h"

// Include the solver header files
#include "integrator.h"  // This is the parent for the three solvers
#include "rk4.h"
#include "ab2.h"
#include "euler.h"

const int num_args = 7;   // Define expected number of command line arguments

// Function to print out values 
void print_values(double t, double x0, double x1)
{
    printf("%15.8f %15.8f %15.8f\n", t, x0, x1);   // Prints time, x, dx
}


// Function takes in a string from input, returns an array with double values.
double* string2double_array(string input)
{
    string temp;                   // Create a temporary array    
    stringstream s(input);         // Break input string into its constituant parts 
    vector<double> nums;           // Create a vector to hold our numbrs (vectors can )

    while (s >> temp) 
    {
      nums.push_back(stod(temp));  // stod means "string to double"
    }

    // Pass vector numbers into an array
    int n = nums.size(); 
    double* output = new double[n];     // Initialise an output array

    // Copy all vector values into respective array values 
    for (int i = 0; i < n; i++)         
    {
        output[i] = nums[i];
    }

    return output;  // Return the array 
}


int main(int argc, char *argv[])
{
    // Get program inputs, make sure we have the correct number of inputs
    // If we don't..break the code and print error message
    if (argc != num_args)
    {
        printf("Wrong number of command line arguments\n");
        exit(99);
    }

    // Which model do we want?
    string model = argv[1];   

    // What should we set our model parameters to?
    string mod_params_str = argv[2];
    double* mod_params = string2double_array(mod_params_str); 

    // What should we set our initial conditions to?
    string i_conds_str = argv[3];
    double* i_conds = string2double_array(i_conds_str); 
    double t = i_conds[0];    // initial time for the system (used explicitly later on)
    double* x = new double[2];
    x[0] = i_conds[1];  // rest of initial state is the rest of the initial conditions array
    x[1] = i_conds[2];
    

    // Which solver do we want?
    string solver = argv[4];   

    // Whats the time step?
    double time_step = stod(argv[5]);   

    // How many time steps should we take?
    int tot_steps = stoi(argv[6]);   

    // Figure out what Model we want
    Model* system_model;

    // Define our model :)
    if (model == "ddo") system_model = new DDOscillator(mod_params);
    else if (model == "lv") system_model = new LotkaVolterra(mod_params);

    // Figure out what integrator we want
    Integrator* system_solver;  
    if (solver == "euler")    system_solver = new Euler(time_step, *system_model); 
    else if (solver == "ab2") system_solver = new AdamsBashforth2(time_step, *system_model);
    else if (solver == "rk4") system_solver = new RungeKutta4(time_step, *system_model);

    // Print initial conditions
    print_values(t, x[0], x[1]);

    // For each time step, solve the system and iterate
    for (int i = 0; i < tot_steps; i++)
    {
        system_solver->Step(t, x);
        t += time_step;
        print_values(t, x[0], x[1]);
    }

    delete [] mod_params;       // Delete things we allocated memory for earlier 
    delete [] i_conds;          // To avoid the memory leaks
    delete [] x; 
}