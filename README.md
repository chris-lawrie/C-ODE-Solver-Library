%---------------------%
% GENERAL INFORMATION %
%---------------------%

This code allows the user to solve either a damped driven oscilator (DDO) or Lotka-Volterra (LV) system of equations. The user has a choice of three different solvers: Euler, Runge-Kutta and Adams-Bashforth. Additional details on the working for each of these methods can be found in sections below. The user is able to define the parameters for the model they choose (DDO or LV), as well as initial conditions for the system, the time step they wish to take, and the total number of steps they wish to take. The code then solves the system and prints out time, and each component of your state vector for each given time step. Examples of how to run the code, and expected outputs, can be found in sections below.


Note that the Runge-Kutta method is intentionally left as slightly repetitional, to make it easier for the user to follow the algorithm's steps. As discussed in class, whilst there are neater ways to package the maths, it substantially abstracts the process and makes it harder to debug. 


%---------------------%
%  RUNNING THE CODE   %
%---------------------%

To run this code - first you must navigate the appropriate location using your terminal (i.e. navigate to wherever you have the code saved). Then you can "make" the code by typing: 

make

Once made, you can specify your inputs in the following fashion. 

./ode_solve <model> <params> <ICs> <integrator> <timestep> <numsteps>

Where: 
<model> is either "ddo" or "lv". 
<params> is a space separated list of parameters for the model you've chosen (the list should contain four items).
<ICs> is a space separated list of initial conditions for the model you've chosen (the list should contain three items).
<integrator> is either "euler", "rk4" or "ab2". 
<timestep> is a single number indicating the size of time-step. 
<numsteps> is a single number indicating the total number of steps the solver should take. 


Examples of functioning inputs are listed below: 

./ode_solve ddo "2.0 1.5 0.25 1.0" "3.0 1.5 0.0" euler 0.1 40  
    (This solves DDO with Euler, for the given params and initial conditions, across 40 timesteps)


./ode_solve lv "1.0 1.8 0.5 0.9" "4.0 0.5 1.0" rk4 0.5 100  
    (This solves LV with rk4, for the given params and initial conditions, across 100 timesteps)




%------------------------------%
%    The Different Models      %
%------------------------------%

* This needs finishing :D 
This section briefly describes the differences in DDO and LV, and explains what the four input parameters map to.

Damped Driven Oscilator (ddo)
    This system is goverened by the following equation:

    q'' + 2*beta*q' + (omega_0)^2 * q = f(t)

    where the solution is:


    Where beta is the damping constant, omega is the natural frequency of the system and f(t) is the applied driving force
    
    The values fed into this as parameters are: 
         <omega F beta omega_0>



Lotka-Volterra (lv)
    This system is goverend by the following equations:

    x[0] = R, fx[0] = R_dot 
    x[1] = F, fx[1] = F_dot

    R_dot = (alpha * R) - (beta * R * F)   
    F_dot = (gamma * R * F) - (delta * F)

    The values fed into this as parameters are: 
        <alpha beta gamma delta>
    
    Where: 
    R     = rabbit population
    F     = fox population 
    alpha = birth rate of rabbits 
    beta  = death rate of rabbits (due to predataion by foxes)
    gamma = birth rate of foxes (per rabit consumed) 
    delta = death rate of foxes



%------------------------------%
%   The Different Solvers      %
%------------------------------%
As discussed earlier there are 3 (three) different solvers to choose from. Each of these methods implements a recursive system to numerically solve the ODE given to it. Each of these methods is written out below.

Euler (euler.cc)
    x_(n+1) = x_n + f(x_n, t_n) * dt


Runge-Kutta 4 (rk4.cc)
    K1 = f(x_n, t_n) * dt
    K2 = f(x_n + k1/2, t_n + dt/2) * dt
    K3 = f(x_n + k2/2, t_n + dt/2) * dt
    K4 = f(x_n + k3, t_n + dt) * dt

    x_(n+1) = x_n + (k1 + k4)/6 + (k2 + k3)/3

Adams-Bashforth 2 (ab2.cc)
    x_(n+1) = x_n + (3/2)*f(x_n, t_n)*dt - (1/2)*f(x_(n-1), t_(n-1))*dt






-----------------------------------
-- Misc C++ Notes just for Chris --
-----------------------------------

C++ appears to be a solid mixture of C and Java. 

'header file'
    - Declaration of what exists for a given class. 
    - Header files don't contain any math in them, they just define instances of new things

'virtual' 
    - allows a subclass of an initial parent class to overwrite a given function

'virtual ..... =0' 
    - forces the subclass of an initial parent class to overwrite a given function
