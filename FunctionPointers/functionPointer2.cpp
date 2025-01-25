#include <iostream>
#include <vector>

template<typename T> 
void print(T value){
    std::cout << "value::: " << value << std::endl;
}
template<>    
void print<int&>(int& value){
    std::cout << "value: " << value << std::endl;
}
template<const int&> 
void print(const int& value){
    std::cout << "value:: " << value << std::endl;
}



void for_each(std::vector<int>& v, void (*func)(int&)){
    std::cout << "for_each1"<<std::endl;
    for(int& value : v){
        func(value);
    }
}

void for_each(const std::vector<int>& v, void (*func)(const int&)){
    std::cout << "for_each2"<<std::endl;
    for(const int& value : v){
        func(value);
    }
}

template<typename T>
void for_each(std::vector<T> v,void(*func)(T)){
    std::cout << "for_each3"<<std::endl;
    for(T value : v){
        func(value);
    }
}
int main(){
    std::vector<int> v{1,2,3,4,5,6};
    for_each<int>(v,print); 
    std::cout << "**********"<< std::endl;

    const std::vector<int> v2{1,2,3,4,5,6};
    for_each<int>(v2,print); 
}