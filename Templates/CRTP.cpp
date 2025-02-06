#include <iostream>

using std::cout;
using std::endl;

template <typename Derived>
class Animal {
    Animal() = default;
    friend Derived;
public:
    void give_sound(){
        Derived& derived = static_cast<Derived&>(*this);
        derived.give_sound();
    }
    void introduce(){
        Derived* derived = static_cast<Derived*>(this);
        derived->introduce();
    }
};   

class Dog : public Animal<Dog>
{
public:
    void give_sound() {
        cout << "Hau hau" << endl;
    }
    void introduce() {
        cout << "I am Dog" << endl;
    }
};

class Cat : public Animal<Cat>
{
public:
    void give_sound() {
        cout << "Miau miau" << endl;
    }
    void introduce() {
        cout << "I am Cat" << endl;
    }
};

template<typename T>
void get_sound(Animal<T>* a){
    a->introduce();
    a->give_sound();
}

int main(){
    Animal<Dog>* d = new Dog;
    Animal<Cat>* c = new Cat;

    d->give_sound();
    c->give_sound();

    get_sound(d);

    return 0;
}
