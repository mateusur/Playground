#include <iostream>
#include <iomanip>
// void foo(int param); //not a specialization, it is an overload

// void foo<int>(int param); //ill-formed

// //this form always works
// template <> void foo<int>(int param); //explicit specialization

// //same as above, but works only if template argument deduction is possible!
// template <> void foo(int param); //explicit specialization

// //same as above, but works only if template argument deduction is possible!
// template void foo(int param); //explicit instantiation

template <typename T>
void print(const T& p) {
  std::cout << p << std::endl;
}

template <>
void print<double>(const double& p) {
  std::cout << std::fixed << std::setprecision(3) << p << std::endl;
}

template <typename T, typename U>
auto sum(T t, U u) {
  return t + u;
}

template <>
auto sum(double t, int u) { //sum <double,double> would more explicit
  return (t + u) * (t + u);
}
// Note: Functions can not be partially specialized!!

void noTemaplteSpecialization() {
  int a{5};
  double b{5.5};
  std::string c{"Hello"};
  double d{1.23456};
  double e{1.0157};
  print<int>(a);
  print(b);
  print(c);
  print(d);
  print(e);
  sum(a, d);
}

void fullTeamplateFunctionSpecialization() {
  double b{5.5};
  double d{1.23456};
  double e{1.015};
  print(b);
  print(d);
  print(e);
  sum(b, b);
}

int main() {
  noTemaplteSpecialization();
  fullTeamplateFunctionSpecialization();
  return 0;
}