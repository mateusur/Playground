#include <iomanip>
#include <iostream>

void matrix_contiguous() {
  constexpr int col = 3;
  constexpr int rows = 5;

  int* array = new int[col * rows];
  for (int i = 0; i < col * rows; ++i) {
    array[i] = i;
  }
  // Print rows wise
  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < col; ++c) {
      std::cout << std::setw(2) << array[r * col + c] << ' ';
    }
    std::cout << '\n';
  }
  // Print column wise
  std::cout << '\n';
  for (int c = 0; c < col; ++c) {
    for (int r = 0; r < rows; ++r) {
      std::cout << std::setw(2) << array[r * col + c] << ' ';
    }
    std::cout << '\n';
  }
  std::cout << '\n';
  delete array;
}
int main() {
  matrix_contiguous();
  return 0;
}