#include <iostream>
#include <memory>

// -------------------------------
// Without Interface Segregation Principle
// -------------------------------

class IMachine {
public:
    virtual void print() = 0;
    virtual void scan() = 0;
    virtual void fax() = 0;
    virtual ~IMachine() = default;
};

class OldPrinter : public IMachine {
public:
    void print() override {
        std::cout << "Printing document" << std::endl;
    }
    void scan() override {
        throw std::logic_error("Scan not supported");
    }
    void fax() override {
        throw std::logic_error("Fax not supported");
    }
};

// -------------------------------
// With Interface Segregation Principle
// -------------------------------

class IPrinter {
public:
    virtual void print() = 0;
    virtual ~IPrinter() = default;
};

class IScanner {
public:
    virtual void scan() = 0;
    virtual ~IScanner() = default;
};

class IFax {
public:
    virtual void fax() = 0;
    virtual ~IFax() = default;
};

class SimplePrinter : public IPrinter {
public:
    void print() override {
        std::cout << "Simple printer printing..." << std::endl;
    }
};

class AllInOneMachine : public IPrinter, public IScanner, public IFax {
public:
    void print() override {
        std::cout << "All-in-one printing..." << std::endl;
    }
    void scan() override {
        std::cout << "All-in-one scanning..." << std::endl;
    }
    void fax() override {
        std::cout << "All-in-one faxing..." << std::endl;
    }
};

int main() {
    try {
        std::unique_ptr<IMachine> oldPrinter = std::make_unique<OldPrinter>();
        oldPrinter->print();
        oldPrinter->scan();
    } catch (const std::exception& ex) {
        std::cout << "Exception: " << ex.what() << std::endl;
    }

    std::unique_ptr<IPrinter> printer = std::make_unique<SimplePrinter>();
    printer->print();

    std::unique_ptr<AllInOneMachine> multi = std::make_unique<AllInOneMachine>();
    multi->scan();
    multi->fax();

    return 0;
}
