#include <iostream>
#include <chrono>
#include <algorithm>

template <typename T>
class DynamicArray{
    T* m_array{};
    int m_length{};
    void alloc(int length){
        m_array = new T[static_cast<std::size_t>(length)];
        m_length = length;
    }
public:
    DynamicArray(int length){
        alloc(length);
    }
    ~DynamicArray(){
        delete []m_array;
    }
    DynamicArray(const DynamicArray& arr) = delete;
    // {
    //     m_length = arr.m_length;
    //     m_array = new T[static_cast<std::size_t>(m_length)];
	// 	std::copy_n(arr.m_array, m_length, m_array); // copy m_length elements from arr to m_array
    // }
    DynamicArray& operator=(const DynamicArray& arr) = delete;
    // {
    //     if(this == &arr){
    //         return *this;
    //     }
    //     delete[] m_array;
    //     alloc(arr.m_length);
	// 	std::copy_n(arr.m_array, m_length, m_array); // copy m_length elements from arr to m_array
    //     return *this;
    // }
    DynamicArray(DynamicArray&& arr) : m_array(arr.m_array), m_length(arr.m_length) {
        arr.m_array = nullptr;
        arr.m_length = 0;
    }
    DynamicArray& operator=(DynamicArray&& arr){
        if(this == &arr){
            return *this;
        }

        delete[] m_array;

        m_array = arr.m_array;
        m_length = arr.m_length;
        arr.m_array = nullptr;
        arr.m_length = 0;
         return *this;
    }
    T& operator[](int index){
        return m_array[index];
    }
    const T& operator[](int index) const {
        return m_array[index];
    }
    int getLength() const {return m_length;}
};

class Timer
{
private:
	// Type aliases to make accessing nested type easier
	using Clock = std::chrono::high_resolution_clock;
	using Second = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<Clock> m_beg { Clock::now() };

public:
	void reset()
	{
		m_beg = Clock::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<Second>(Clock::now() - m_beg).count();
	}
};

DynamicArray<int> cloneArrayAndDouble(const DynamicArray<int>& arr){
    DynamicArray<int> dbl(arr.getLength());
    for(int i = 0; i < arr.getLength(); ++i){
        dbl[i] = arr[i]*2;
    }
    return dbl;
}

int main(){
    Timer t;
    DynamicArray<int> arr(1'000'000);
    for(int i = 0; i < arr.getLength(); ++i){
        arr[i] = i;
    }
    arr = cloneArrayAndDouble(arr);

    std::cout << t.elapsed();

    return 0;
}