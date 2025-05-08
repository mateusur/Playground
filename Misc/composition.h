#pragma once
#include <iostream>

using std::cout;
using std::endl;

// "Has-a" relationship with ownership: One class owns the other and manages its
// lifetime.
class Engine {
 public:
  Engine() { cout << "Engine created" << endl; }
  ~Engine() { cout << "Engine destroyed" << endl; }
};

class Vehicle {
 private:
  Engine engine;  
  
 public:
  Vehicle() { cout << "Vehicle created" << endl; }
  ~Vehicle() { cout << "Vehicle destroyed" << endl; }
};
