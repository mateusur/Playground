#include <iostream>
#include <vector>

void for_each(std::vector<int>& v, void (*func)(int&)) {
  std::cout << "for_each1" << std::endl;
  for (int& value : v) {
    func(value);
  }
}
int main() {
  std::vector<int> v{1, 2, 3, 4, 5};
  for_each(v, [](int& i) { std::cout << "value: " << i << std::endl; });

  return 0;
}