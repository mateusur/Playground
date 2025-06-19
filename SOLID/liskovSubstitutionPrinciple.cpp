#include <iostream>
#include <vector>
#include <memory>
#include <string>

// -------------------------------
// Without Liskov Substitution Principle
// -------------------------------

class Bird {
public:
    virtual void fly() {
        std::cout << "Bird is flying" << std::endl;
    }
};

class Ostrich : public Bird {
public:
    void fly() override {
        throw std::logic_error("Ostriches can't fly!");
    }
};

void makeBirdFly(Bird* bird) {
    bird->fly();
}

// -------------------------------
// With Liskov Substitution Principle
// -------------------------------

class BirdLSP {
public:
    virtual void move() const = 0;
    virtual ~BirdLSP() = default;
};

class FlyingBird : public BirdLSP {
public:
    void move() const override {
        std::cout << "Flying in the sky" << std::endl;
    }
};

class NonFlyingBird : public BirdLSP {
public:
    void move() const override {
        std::cout << "Walking on the ground" << std::endl;
    }
};

int main() {
    try {
        Bird* ostrich = new Ostrich();
        makeBirdFly(ostrich); 
        delete ostrich;
    } catch (const std::exception& ex) {
        std::cout << "Exception caught: " << ex.what() << std::endl;
    }

    std::vector<std::shared_ptr<BirdLSP>> birds = {
        std::make_shared<FlyingBird>(),
        std::make_shared<NonFlyingBird>()
    };

    for (const auto& bird : birds) {
        bird->move();
    }

    return 0;
}
