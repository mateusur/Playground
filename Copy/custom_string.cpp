#include <iostream>


class String {
    private:
    unsigned int m_size{};
    char* m_buffer{};
public:
    String(const char* string){
        m_size = strlen(string);
        m_buffer = new char[m_size+1];
        memcpy(m_buffer,string,m_size);
        m_buffer[m_size] = 0;
    }

    ~String(){
        delete[] m_buffer;
    }

    String(const String& string) {
        std::cout << "copy constructor called" << std::endl;
        m_size = string.m_size;
        m_buffer = new char[m_size+1];
        memcpy(m_buffer,string.m_buffer,m_size);
        m_buffer[m_size]= 0;
    }
    String& operator=(const String& string) {
        if(this==&string){
            return *this;
        }
        delete[] m_buffer;

        std::cout << "copy operator called" << std::endl;
        m_size = string.m_size;
        m_buffer = new char[m_size+1];
        memcpy(m_buffer,string.m_buffer,m_size);
        m_buffer[m_size]= 0;
    }
    friend std::ostream& operator<<(std::ostream& os, const String& string);
};

std::ostream& operator<<(std::ostream& os, const String& string){
    os << string.m_buffer;
    return os;
}

int main(){
    String string = "Playground";
    std::cout << string << std::endl;

    String second {"fun"};

    std::cout << second << std::endl;

    second = string;

    std::cout << string << std::endl;
    std::cout << second << std::endl;

    return 0;
}