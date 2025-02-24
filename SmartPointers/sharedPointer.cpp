#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::shared_ptr;

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

template<typename T>
class Shared_pointer{
    T* m_ptr;
    int* m_counter;
public:
    Shared_pointer(T* ptr = nullptr) {
        if(ptr){
            m_ptr = ptr;
            m_counter = new int(1);
        }
    }
    Shared_pointer(const Shared_pointer& other){
        m_ptr = other.m_ptr;
        m_counter = other.m_counter;
        if(m_counter){
          (*m_counter)++;  
        }
    }
    Shared_pointer& operator=(const Shared_pointer& other){
        if(this != &other){
            release();
            m_ptr = other.m_ptr;
            m_counter = other.m_counter;
            if(m_counter){
                (*m_counter)++;  
            }
        }
        return *this;
    }
    ~Shared_pointer(){
        release();
    }
    int use_count() const {
        return m_counter;
    }
    void release(){
        if(m_counter){
            (*m_counter)--;
            if((*m_counter)==0){
                delete m_ptr;
                delete m_counter;
                m_ptr = nullptr;
                m_counter = nullptr;
            }
        }
    }
    T* operator->() {
        return m_ptr;
    }
    T& operator*(){
        return *m_ptr;
    }
};

int main(){
    {
        shared_ptr<Person> mat(new Person{"Mateusz"});
        {
            shared_ptr<Person> mik(new Person{"Mikolaj"});
            mat = mik;
            { // Mateusz destroyed
                shared_ptr<Person> pit(new Person{"Piotr"});
                mat = pit;
            }
        } // Mikolaj destroyed
    } // Piotr destroyed
    cout << "******"<<endl;
    {
        Shared_pointer<Person> mat(new Person{"Mateusz"});
        {
            Shared_pointer<Person> mik(new Person{"Mikolaj"});
            mat = mik;
            { // Mateusz destroyed
                Shared_pointer<Person> pit(new Person{"Piotr"});
                mat = pit;
            }
        } // Mikolaj destroyed
    } // Piotr destroyed
    cout << "******"<<endl;
    {
        shared_ptr<Person> mat(new Person{"Mateusz"});
        mat->getName();
        (*mat).getName();
    }
    {
        Shared_pointer<Person> mik(new Person{"Mikolaj"});
        cout << mik->getName() << endl;
         cout << (*mik).getName()<< endl;
    }
    return 0;
}