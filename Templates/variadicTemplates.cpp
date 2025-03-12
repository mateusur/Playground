#include <iostream>
#include <string>

template <typename T>
T Sum(T v) {
  return v;
}

template <typename T, typename... Args>
auto Sum(T first, Args... args) {
  return first + Sum(args...);
}

std::string operator+(std::string s, int i) { return s + std::to_string(i); }
std::string operator+(int i, std::string s) { return std::to_string(i) + s; }

// Fold expressions (since C++17)
template <typename... Args>
auto SumFold(Args... args) {
  return (args + ...);
}

template <typename... Args>
void Print(Args&&... args) {
  ((std::cout << args << " "), ...) << "\n";
}
template <typename... Args>
bool AllDivisable(int divisor, Args&&... args) {
  return ((args % divisor == 0) && ...);
}
int main() {
  std::cout << Sum(3, 10.0, 7) << std::endl;
  std::cout << Sum<int, std::string, int, int>(1, "3", 10, 7) << std::endl;

  std::cout << SumFold<int, std::string, int>(3, "10", 7) << std::endl;
  std::cout << SumFold(3, -7, 7) << std::endl;

  Print<int, std::string, int>(3, "10", 7);

  std::cout << (AllDivisable(2, 0, 2, 382, 12) == 0 ? "false" : "true")
            << std::endl;
  std::cout << (AllDivisable(10, 5, 10, 1560, 2150) == 0 ? "false" : "true")
            << std::endl;
}