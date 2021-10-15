echo "Verify Faulty Inputs" 
./ode_solve dfjkdsahfdsakj hdsakjfhgas kj
echo "------------------------------------------------------------------------" 
echo "rk4" 
./ode_solve ddo "0.5 1.0 0.25 1.0" "0.0 0.0 0.0" rk4 1.8849555922 10 

echo "------------------------------------------------------------------------" 
echo "ab2" 
./ode_solve ddo "0.5 1.0 0.25 1.0" "0.0 0.0 0.0" ab2 1.8849555922 10 

echo "------------------------------------------------------------------------" 
echo "euler" 
./ode_solve ddo "0.5 1.0 0.25 1.0" "0.0 0.0 0.0" euler 1.8849555922 10


echo "------------------------------------------------------------------------" 
echo "Model Baboon vs Cheetah Predator-Prey relationship using wikipedia values"
echo "Output to baboon_vs_cheetah.txt"

./ode_solve lv "1.1 0.4 0.1 0.4" "0.0 10.0 10.0" rk4 0.02 5000 > baboon_vs_cheetah.txt

echo "------------------------------------------------------------------------" 
echo "Model Rabbits vs Foxes Predator-Prey relationship using assignment values"
./ode_solve lv "1.0 0.2 0.1 0.2" "0.0 1.0 2.0" rk4 0.25 200 > rabbit_vs_fox.txt