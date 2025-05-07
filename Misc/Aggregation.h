#pragma once
#include <iostream>

using std::string;
using std::cout;
using std::endl;

//"Has-a" relationship
class Car {
    public:
        string model;
        Car(string m) : model(m) {}
    };
    
    class PersonWithCar {
    public:
        string name;
        Car* car; // Aggregation: PersonWithCar uses Car, but doesn't own it
    
        PersonWithCar(string n, Car* c) : name(n), car(c) {}
    
        void displayCar() {
            if (car)
                cout << name << " drives a " << car->model << endl;
        }
    };
    