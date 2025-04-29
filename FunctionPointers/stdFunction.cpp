#include <iostream>
#include <functional>

//Easy
void greet(){
    std::cout<< "Easy Hello" << std::endl;
}

//Medium
void mediumTwice(int x, std::function<void(int)> func){
    func(x);
    func(x);
}

int main(){
    std::function<void()> easy = greet;
    easy();

    mediumTwice(9,[](int x){std::cout<< "Double print: " << x << std::endl; });
}