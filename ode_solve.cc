// General driver code for a given choice of ODE (eg. ddo, LV2)
// and a given choice of solver (Euler, ddo, ab2)
// *** how to check and read in and parse command line inputs?
// *** how to print in c++? LMAO :D 

#include "ddo.h"
#include "lv.h"
#include "rk4.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

const int num_args = 7;   // Expected number of command line arguments

// Function to print out values 
void print_values(double t, double x, double dx)
{
    printf("%15.8f %15.8f %15.8f\n", t, x, dx);   // Prints time, x, dx
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
    double* output = new double[n];

    for (int i = 0; i < n; i++) 
    {
        output[i] = nums[i];
    }

    return output; 
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
    double [] mod_params = string2double_array(mod_params_str); 

    // What should we set our initial conditions to?
    string i_conds_str = argv[3];
    double [] i_conds = string2double_array(i_conds_str); 

    // Which solver do we want?
    string solver = argv[4];   

    // Whats the time step?
    double time_step = stod(argv[5]);   

    // How many time steps should we take?
    int tot_steps = stoi(argv[6]);   



    // Print initial conditions
    print_values(t, dx[0], dx[1]);


    // Figure out what Model we want
    Model system_model;

    // Define our model :)
    if (model == "ddo") system_model = new DDOscillator(mod_params);
    else if (model == "lv") system_model = new LotkaVolterra(mod_params);


    // Figure out what integrator we want
    Integrator system_solver;  
    if (solver == "Euler")    system_solver = new Euler(time_step, system_model); 
    else if (solver == "ab2") system_solver = new AdamsBashforth2(time_step, system_model);
    else if (solver == "rk4") system_solver = new RungeKutta4(time_step, system_model);


    // For each time step, solve the system and iterate
    for (int i = 0; i < tot_steps; i++)
    {
      //  t += dt;
        print_values(t, dx[0], dx[1]);
    }

    delete [] mod_params;
    delete [] i_conds;
}