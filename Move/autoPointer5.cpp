#include <iostream>

template <typename T>
class Auto_ptr5 {
  T* m_ptr{};

 public:
  Auto_ptr5(T* ptr = nullptr) : m_ptr(ptr) {}
  ~Auto_ptr5() { delete m_ptr; }
  Auto_ptr5(const Auto_ptr5& a) = delete;
  Auto_ptr5& operator=(const Auto_ptr5& a) = delete;
  Auto_ptr5(Auto_ptr5&& a) : m_ptr(a.m_ptr) { a.m_ptr = nullptr; }
  Auto_ptr5& operator=(Auto_ptr5&& a) noexcept {
    // Self-assignment detection
    if (this == &a) return *this;
    // Release any resource we're holding
    delete m_ptr;
    // Transfer ownership of a.m_ptr to m_ptr
    m_ptr = a.m_ptr;
    a.m_ptr = nullptr;
    return *this;
  }
  T& operator*() const { return *m_ptr; }
  T* operator->() const { return m_ptr; }
  bool isNull() const { return m_ptr == nullptr; }
};