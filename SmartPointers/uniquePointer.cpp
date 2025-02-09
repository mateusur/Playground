#include <iostream>
#include <memory>

class Person{
    std::string m_name{};
public:
    Person(std::string name) : m_name{name} {
        std::cout << "Person ("<<m_name<<") created" << std::endl;
    };
    ~Person(){
        std::cout << "Person ("<<m_name<<") destroyed" << std::endl;
    }
    std::string getName() const{
        return m_name;
    }
};
template <typename T>
class Unique_pointer {
    T* m_ptr;
public:
    Unique_pointer(T* ptr = nullptr) : m_ptr{ptr} {};
    Unique_pointer(const Unique_pointer& other) = delete;
    Unique_pointer& operator=(const Unique_pointer& other) = delete;
    Unique_pointer(Unique_pointer&& other){
        m_ptr = other.m_ptr;
        other.m_ptr = nullptr;
    }
    Unique_pointer& operator=(Unique_pointer&& other){
        if(other == this){
            return *this;
        }
        delete m_ptr;

        m_ptr = other.m_ptr;
        other.m_ptr = nullptr;
    }
    ~Unique_pointer(){
        delete m_ptr;
    }
    T* get(){
        return m_ptr;
    }
    T* operator->(){
        return m_ptr;
    }
    T& operator*(){
        return *m_ptr;
    }
    operator bool(){
        return m_ptr != nullptr;
    }

};

int main() {
    {std::unique_ptr<Person> mat(new Person{"Mateusz"});
    mat.get()->getName();
    std:: cout << mat->getName() << std::endl;
    std:: cout << (*mat).getName() << std::endl;
    if(mat){
        {}
    }
    //move
        std::unique_ptr<Person> mat_copy(std::move(mat));
        if(mat)
        std:: cout << mat->getName() << std::endl;
        if(mat_copy)
        std:: cout << "Mat copy:" << mat_copy->getName() << std::endl;
    }
    std:: cout << "**************" << std::endl;
    {
    Unique_pointer<Person> kas(new Person{"Kasia"});
    kas.get()->getName();
    
    std:: cout << kas->getName() << std::endl;
    std:: cout << (*kas).getName() << std::endl;
    if(kas){
        {}
    }
    //move
        Unique_pointer<Person> kas_copy(std::move(kas));
        if(kas)
        std:: cout << kas->getName() << std::endl;
        if(kas_copy)
        std:: cout << "Kas copy:" << kas_copy->getName() << std::endl;
    }
    return 0;
}