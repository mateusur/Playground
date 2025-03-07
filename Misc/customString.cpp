#include <string.h>

#include <cstring>
#include <iostream>
#include <ostream>

class String {
  char* m_ptr;
  size_t m_size;

 public:
  String() {
    m_size = 0;
    m_ptr = nullptr;
  }
  String(const char* text) {
    m_size = strlen(text);
    m_ptr = new char[m_size + 1];
    strcpy(m_ptr, text);
  }
  String(const String& other) {
    m_size = other.m_size;
    m_ptr = new char[m_size + 1];
    strcpy(m_ptr, other.m_ptr);
  }
  String(String&& other) noexcept {
    m_size = other.m_size;
    m_ptr = other.m_ptr;
    other.m_size = 0;
    other.m_ptr = nullptr;
  }
  String& operator=(const String& other) {
    if (this != &other) {
      delete[] m_ptr;

      m_size = other.m_size;
      m_ptr = new char[m_size + 1];
      strcpy(m_ptr, other.m_ptr);
    }
    return *this;
  }
  String& operator=(String&& other) {
    if (this != &other) {
      delete[] m_ptr;

      m_size = other.m_size;
      m_ptr = other.m_ptr;
      other.m_size = 0;
      other.m_ptr = nullptr;
    }
    return *this;
  }

  String operator+(const String& other) const {
    String result;

    result.m_size = m_size + other.m_size;
    result.m_ptr = new char[result.m_size + 1];

    std::memcpy(result.m_ptr, m_ptr, m_size);
    std::memcpy(result.m_ptr + m_size, other.m_ptr, other.m_size);
    result.m_ptr[result.m_size] = '\0';

    return result;
  }
  size_t size() const { return m_size; }
  ~String() { delete[] m_ptr; }
  void print() {
    if (m_ptr) {
      std::cout << m_ptr << std::endl;
    }
  }
  friend std::ostream& operator<<(std::ostream& os, const String& str);
};

std::ostream& operator<<(std::ostream& os, const String& str) {
  return os << str.m_ptr;
}

int main() {
  String abc("Hello world");

  // Copy
  std::cout << "Copying" << std::endl;
  String copyOfAbc = abc;
  String copyOfAbc2("123");
  std::cout << copyOfAbc << std::endl;
  std::cout << copyOfAbc2 << std::endl;
  copyOfAbc2 = abc;
  std::cout << copyOfAbc2 << std::endl;

  // Move
  std::cout << "\nMoveing" << std::endl;
  String moveOfAbc(std::move(abc));
  std::cout << moveOfAbc << std::endl;
  abc = std::move(moveOfAbc);
  std::cout << abc << std::endl;

  // Concatenation
  std::cout << "\nConcatenation" << std::endl;
  String a(" my friend");
  std::cout << abc + a << std::endl;

  return 0;
}