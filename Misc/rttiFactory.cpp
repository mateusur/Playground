#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <functional>
#include <typeinfo>

class base {
public:
    virtual ~base() {}
    virtual std::unique_ptr<base> clone() const = 0;
};

class derived_a : public base {
public:
    std::unique_ptr<base> clone() const override {
        return std::make_unique<derived_a>(*this);
    }
};

class derived_b : public base {
public:
    std::unique_ptr<base> clone() const override {
        return std::make_unique<derived_b>(*this);
    }
};

class factory {
public:
    template <typename T>
    void register_type() {
        std::string type_name = typeid(T).name();
        creators[type_name] = []() -> std::unique_ptr<base> {
            return std::make_unique<T>();
        };
    }

    std::unique_ptr<base> create(const std::string& type_name) {
        auto it = creators.find(type_name);
        if (it != creators.end()) {
            return it->second();
        }
        return nullptr;
    }

private:
    std::map<std::string, 
             std::function<std::unique_ptr<base>()>> creators;
};

int main() {
    factory my_factory;
    my_factory.register_type<derived_a>();
    my_factory.register_type<derived_b>();

    std::unique_ptr<base> obj_a = 
         my_factory.create(typeid(derived_a).name());
    std::unique_ptr<base> obj_b = 
         my_factory.create(typeid(derived_b).name());

    if (obj_a) {
        std::cout << "Created object of type: " 
                  << typeid(*obj_a).name() << std::endl;
    }

    if (obj_b) {
        std::cout << "Created object of type: " 
                  << typeid(*obj_b).name() << std::endl;
    }

    return 0;
}