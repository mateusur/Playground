#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base constructor\n"; }
    virtual ~Base() { cout << "Base destructor\n"; }
};

class Intermediate1 : public Base {
public:
    Intermediate1() { cout << "Intermediate1 constructor\n"; }
    virtual ~Intermediate1() { cout << "Intermediate1 destructor\n"; }
};

class Intermediate2 : public Base {
public:
    Intermediate2() { cout << "Intermediate2 constructor\n"; }
    virtual ~Intermediate2() { cout << "Intermediate2 destructor\n"; }
};

class Derived : public Intermediate1, public Intermediate2 {
public:
    Derived() { cout << "Derived constructor\n"; }
    ~Derived() { cout << "Derived destructor\n"; }
};

int main() {
    Derived d;
    return 0;
}
