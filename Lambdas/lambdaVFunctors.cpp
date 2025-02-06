#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
template<typename T>
std::ostream& operator<<(std::ostream& os,const vector<T>& v){
    for(const auto& i : v){
        os << i << ' ';
    }
    os << '\n';
    return os;
}

struct BiggerThan0
{
    bool operator()(int i){
        return i >0;
    }    
};
struct BiggerThanX
{
    int X;
    explicit BiggerThanX(int x) : X(x){};

    bool operator()(int i){
        return i > X;
    }    
};

// class NotMutable
// {
//     int X;
// public:
//     explicit NotMutable(int x) : X(x){};
//     void operator()() const{ // won't work without mutable
//         X++;
//     }    
// };

void example1(){
    vector<int> v{1,2,4,13,23};
    auto BiggerThan0l = [](int i){return i > 0;};
    BiggerThan0 biggerThan0;
    cout << std::count_if(v.begin(), v.end(),biggerThan0) << endl;
    cout << std::count_if(v.begin(), v.end(),BiggerThan0l) << endl;
}

void example2(){
    vector<int> v{1,2,4,13,23};
    int x = 10;
    auto BiggerThanXl = [&x](int i){return i > x;};
    BiggerThanX biggerThanX(x);
    cout << std::count_if(v.begin(), v.end(),biggerThanX) << endl;
    cout << std::count_if(v.begin(), v.end(),BiggerThanXl) << endl;
}

void example3(){
    // int x = 10;
    // auto g = [x]() {
	// 	x++; //This Won't work because we capture by value in not mutable lambda
	// 	std::cout <<"Lambda print: "<< x << std::endl;
	// };
	// g();
    // NotMutable notMutable(x);
    // notMutable();
}

int main(){
    // example1();
    // example2();
    example3();

}