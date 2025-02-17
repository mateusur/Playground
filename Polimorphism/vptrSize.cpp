#include <iostream>

using std::cout;
using std::endl;

class Person{
    uint8_t m_age;
    uint32_t m_salary;
public:
    Person(uint8_t age,uint32_t salary) : m_age{age}, m_salary{salary} {};
    ~Person() = default;
};

class Vperson{
    uint8_t m_age;
    uint32_t m_salary;
public:
    Vperson(uint8_t age,uint32_t salary) : m_age{age}, m_salary{salary} {};
    virtual ~Vperson() = default;
};

class VMale : public Vperson {
    uint8_t m_height;
public:
    VMale(uint8_t age,uint32_t salary, uint8_t height) : Vperson(age,salary), m_height(height){};
    ~VMale() override = default;
};

class Empty{
public:
    Empty() = default;
    ~Empty() = default;
};

int main(){
    Person a{25,4000};
    cout << "Person Size without vptr: " << sizeof(a) << endl;

    Vperson b{25,4000};
    cout << "Vperson Size with vptr: " << sizeof(b) << endl;

    VMale c{25,4000,178};
    cout << "VMale (num of vptr); Size: " << sizeof(c) << endl;

    Empty d;
    cout << "Size of empty class: " << sizeof(d) << endl;
    return 0;
}