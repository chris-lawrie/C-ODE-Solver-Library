// General driver code for a given choice of ODE (eg. ddo, LV2)
// and a given choice of solver (Euler, ddo, ab2)

// *** how to check and read in and parse command line inputs?
// *** how to print in c++? LMAO :D 

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
    double[] output = new double[n];

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

    // What should we set our parameters to?
    string params_str = argv[2];
    double[] params = string2double_array(params_str);    // "4.0 5.0 6.0 7.0"







    // // Creating and initialising a VLA of size n for solving system
    // double dx[n];
    // for (int i = 0; i < n; i++) dx[i] = 0;

    // // Create a pointer to the new integrator and assigns memory for the integrator object
    // Integrator *solver = integrator_new(n, dt, &rhs);

    // // Print initial conditions
    // print_values(t, dx[0], dx[1]);

    // // For each time step, solve the system and iterate
    // for (int i = 0; i < N; i++)
    // {
    //     integrator_step(solver, t, dx);
    //     t += dt;
    //     print_values(t, dx[0], dx[1]);
    // }
    // integrator_free(solver);
}