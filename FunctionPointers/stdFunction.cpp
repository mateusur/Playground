#include <iostream>
#include <functional>
#include <cassert>
//Easy
void greet(){
    std::cout<< "Easy Hello" << std::endl;
}

//Medium
void mediumTwice(int x, std::function<void(int)> func){
    func(x);
    func(x);
}

//Hard
struct MyMath
{
    int sum(int a, int b){
        return a+b; 
    }

    int divide(int a, int b){
        assert(b!=0);
        return a/b;
    }
};

int main(){
    std::function<void()> easy = greet;
    easy();

    mediumTwice(9,[](int x){std::cout<< "Double print: " << x << std::endl; });

    MyMath my_sum;
    std::function<int(int,int)> sum = std::bind(&MyMath::sum,my_sum,std::placeholders::_1,std::placeholders::_2);
    std::function<int(int)> divide_by_two = std::bind(&MyMath::divide,my_sum,std::placeholders::_1,2);

    std::cout << "Sum: " << sum(10,10) << std::endl;
    std::cout << "Dividing by two: " << divide_by_two(10) << std::endl;

}