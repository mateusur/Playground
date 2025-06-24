#include <iostream>
#include <memory>

// -------------------------------
// Without Dependency Inversion Principle
// -------------------------------

class LightBulb {
public:
    void turnOn() {
        std::cout << "LightBulb: ON" << std::endl;
    }
    void turnOff() {
        std::cout << "LightBulb: OFF" << std::endl;
    }
};

class LightSwitchBad {
public:
    LightSwitchBad()
        : bulb(std::make_unique<LightBulb>()), on(false) {}

    void toggle() {
        if (on) {
            bulb->turnOff();
            on = false;
        } else {
            bulb->turnOn();
            on = true;
        }
    }

private:
    std::unique_ptr<LightBulb> bulb;  // Direct dependency on concrete
    bool on;
};

// -------------------------------
// With Dependency Inversion Principle
// -------------------------------

// High- and low-level modules both depend on this abstraction
class ISwitchable {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual ~ISwitchable() = default;
};

// Low-level module implements abstraction
class LightBulbGood : public ISwitchable {
public:
    void turnOn() override {
        std::cout << "LightBulbGood: ON" << std::endl;
    }
    void turnOff() override {
        std::cout << "LightBulbGood: OFF" << std::endl;
    }
};

// High-level module depends on abstraction, injected via constructor
class LightSwitch {
public:
    LightSwitch(std::shared_ptr<ISwitchable> device)
        : device(device), on(false) {}

    void toggle() {
        if (on) {
            device->turnOff();
            on = false;
        } else {
            device->turnOn();
            on = true;
        }
    }

private:
    std::shared_ptr<ISwitchable> device;
    bool on;
};

int main() {
    // Violates DIP
    LightSwitchBad badSwitch;
    badSwitch.toggle(); // ON
    badSwitch.toggle(); // OFF

    // Respects DIP
    auto bulb = std::make_shared<LightBulbGood>();
    LightSwitch goodSwitch(bulb);
    goodSwitch.toggle(); // ON
    goodSwitch.toggle(); // OFF

    return 0;
}
