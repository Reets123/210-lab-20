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
        for (int i = 0; i < SIZE; i++)
            prices[i] = (rand() % (MAX - MIN + 1) + MIN) / 100.0;
    }

    Chair(int l, double p[]) {
        leg = l;
        prices = new double[SIZE];
        for (int i = 0; i < SIZE; i++) {
            prices[i] = p[i];
        }
    }

    // setters and getters
    void setLegs(int l) { legs = l; }
    int getLegs() { return legs; }
    void setPrices(double p1, double p2, double p3) {
        prices[0] = p1; prices[1] = p2; prices[2] = p3;
    }
    
    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - Legs: " << legs << endl;
        cout << "Price history: ";
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }

    ~Chair() {
        delete[] prices;
    }
};

int main() {
    cout << fixed << setprecision(2);

    Chair* chairPtr = new Chair;
    chairPtr->print();

    double prices1[SIZE] = {525.25, 434.34, 252.52};
    Chair* livingChair = new Chair(3, prices1);
    livingChair->print();
    delete livingCh