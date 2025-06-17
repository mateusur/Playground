#include <iostream>
#include <vector>
#include <memory>
#include <string>

// -------------------------------
// Without Open-Closed Principle
// -------------------------------

class Rectangle {
public:
    double width, height;
};

class Circle {
public:
    double radius;
};

class AreaCalculatorBad {
public:
    double calculateArea(const std::vector<void*>& shapes, const std::vector<std::string>& types) {
        double area = 0.0;
        for (size_t i = 0; i < shapes.size(); ++i) {
            if (types[i] == "rectangle") {
                Rectangle* r = static_cast<Rectangle*>(shapes[i]);
                area += r->width * r->height;
            } else if (types[i] == "circle") {
                Circle* c = static_cast<Circle*>(shapes[i]);
                area += 3.1415 * c->radius * c->radius;
            }
            // Every new shape requires modifying this function - violates Open-Closed Principle
        }
        return area;
    }
};

// -------------------------------
// With Open-Closed Principle
// -------------------------------

class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

class RectangleOCP : public Shape {
public:
    RectangleOCP(double w, double h) : width(w), height(h) {}
    double area() const override { return width * height; }
private:
    double width, height;
};

class CircleOCP : public Shape {
public:
    CircleOCP(double r) : radius(r) {}
    double area() const override { return 3.1415 * radius * radius; }
private:
    double radius;
};

class AreaCalculatorGood {
public:
    double calculateArea(const std::vector<std::shared_ptr<Shape>>& shapes) {
        double area = 0.0;
        for (const auto& shape : shapes) {
            area += shape->area();
        }
        return area;
    }
};

// -------------------------------
// Usage
// -------------------------------

int main() {
    std::vector<std::shared_ptr<Shape>> shapes = {
        std::make_shared<RectangleOCP>(3.0, 4.0),
        std::make_shared<CircleOCP>(5.0)
    };

    AreaCalculatorGood calculator;
    std::cout << "Total area: " << calculator.calculateArea(shapes) << std::endl;

    return 0;
}
