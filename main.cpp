// Lab 20: Chair Maker 3000
// COMSC-210 - Ibrahim Alatig 

//     Chair                      
// -------------------
// - legs: int                                   
//- prices: double*                            
//-------------------
// + Chair()                                     
// + Chair(int l, double p[])                    
// + void setLegs(int l)                        
// + int getLegs(): int                         
// + void setPrices(double p1, double p2, double p3) 
// + double getAveragePrices(): double           
// + void print()                                
// + ~Chair()          

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
    Chair() : legs((rand() % 2) + 3), prices(new double[SIZE]) { // Constructor initialization list
        // Random prices between $100.00 and $999.99
        const int MIN = 10000, MAX = 99999;
        for (int i = 0; i < SIZE; i++)
            prices[i] = (rand() % (MAX - MIN + 1) + MIN) / 100.0;
    }

     Chair(int l, double p[]) : legs(l), prices(new double[SIZE]) { // Constructor initialization list
        for (int i = 0; i < SIZE; i++) {
            prices[i] = p[i];
        }
    }

    // Copy Constructor
    Chair(const Chair& other) : legs(other.legs), prices(new double[SIZE]) { // Proper copy constructor
        for (int i = 0; i < SIZE; i++) {
            prices[i] = other.prices[i];
        }
    }

     // Assignment Operator
    Chair& operator=(const Chair& other) { // Proper assignment operator
        if (this != &other) { // Prevent self-assignment
            delete[] prices; // Clean up old memory
            legs = other.legs;
            prices = new double[SIZE]; // Allocate new memory
            for (int i = 0; i < SIZE; i++) {
                prices[i] = other.prices[i]; // Copy prices
            }
        }
        return *this;
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
    srand(static_cast<unsigned int>(time(0)));
    
    cout << fixed << setprecision(2);

    Chair* chairPtr = new Chair;
    chairPtr->print();

    double prices1[SIZE] = {525.25, 434.34, 252.52};
    Chair* livingChair = new Chair(3, prices1);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    // Creating dynamic array of chair objects using default constructors
    Chair* collection = new Chair[SIZE];
    for (int i = 0; i < SIZE; i++) {
        collection[i] = Chair(); // Uses default constructor
        collection[i].print();
    }

    delete[] collection;
    delete chairPtr;
    chairPtr = nullptr;

    return 0;
}