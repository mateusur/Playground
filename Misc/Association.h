#include <iostream>
using std::cout;
using std::endl;
using std::string;


// "Uses-a" relationship
class Address {
public:
    string city;
    Address(string c) : city(c) {}
};

class Person {
public:
    string name;
    Person(string n) : name(n) {}

    // Association: Person just uses Address
    void displayAddress(Address* addr) {
        cout << name << " lives in " << addr->city << endl;
    }
};