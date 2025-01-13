#include <iostream>

template <typename T>
void print(const T& p){
    std::cout << p << std::endl; 
}

int main(){
    int a{5};
    double b{5.5};
    std::string c{"Hello"};

    print<int>(a);
    print(b);
    print(c);

    return 0;
}