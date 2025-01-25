 #include <iostream>
#include <vector>

void print(int& value){
    std::cout << "value: " << value << std::endl;
}
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

int main(){
    std::vector<int> v{1,2,3,4,5,6};
    for_each<int>(v,print); 
    std::cout << "**********"<< std::endl;

    const std::vector<int> v2{1,2,3,4,5,6};
    for_each<int>(v2,print); 
}