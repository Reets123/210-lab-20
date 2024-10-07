// Lab 20: Chair Maker 3000
// COMSC-210 - Ibrahim Alatig 

#include <iostream>
#include <iomanip>
#include <cstdlib> 
#include <ctime>   

using namespace std;

const int SIZE = 3;

class Chair {
private:
    int legs;
    double* prices;
public:
    // constructors
    Chair() {
        // Seed the random number generator
        srand(static_cast<unsigned int>(time(0)));
        
        // Randomly select 3 or 4 legs
        legs = (rand() % 2) + 3; // Randomly selects 3 or 4
        prices = new double[SIZE];
        
        // Random prices between $100.00 and $999.99
        const int MIN = 10000, MAX = 99999;
        for (int i = 0;