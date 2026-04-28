#include <iostream>
#include <string>
#include <cmath>

// ============================================================
// CLASS DEFINITIONS
// ============================================================

class Rectangle; // forward declaration

class Point {
private:
    double x;
    double y;
public:
    // TODO 1: Constructor with member initializer list (double x, double y)
    Point(double x, double y) : x(x), y(y) {}

    // TODO 2: const getter for x
    double getX() const { return x; }

    // TODO 3: const getter for y
    double getY() const { return y; }

    // TODO 4: const display()
    void display() const { std::cout << "(" << x << ", " << y << ")"; }

    // TODO 5: declare Rectangle as friend class
    friend class Rectangle;
};

class Rectangle {
private:
    Point topLeft;
    Point bottomRight;
public:
    // TODO 6: constructor with member initializer list
    Rectangle(double x1, double y1, double x2, double y2)
        : topLeft(x1, y1), bottomRight(x2, y2) {}

    // TODO 7: const getWidth()
    double getWidth() const { return std::abs(bottomRight.x - topLeft.x); }

    // TODO 8: const getHeight()
    double getHeight() const { return std::abs(topLeft.y - bottomRight.y); }

    // TODO 9: const getArea()
    double getArea() const { return getWidth() * getHeight(); }

    // TODO 10: const display()
    void display() const {
        std::cout << "Rectangle: ";
        topLeft.display();
        std::cout << " to ";
        bottomRight.display();
        std::cout << std::endl;
    }

    // TODO 11: declare isSameSize as friend function
    friend bool isSameSize(const Rectangle& r1, const Rectangle& r2);
};

// TODO 12: implement isSameSize
bool isSameSize(const Rectangle& r1, const Rectangle& r2) {
    return (r1.getWidth() == r2.getWidth()) &&
           (r1.getHeight() == r2.getHeight());
}

class ConstDemo {
private:
    int value;
public:
    // TODO 13: constructor with member initializer list
    ConstDemo(int v) : value(v) {}

    // TODO 14: const getValue()
    int getValue() const { return value; }

    // TODO 15: NON-const doubleValue() — multiplies value by 2
    void doubleValue() { value *= 2; }

    // TODO 16: const constGetDouble() — returns value * 2 without modifying
    int constGetDouble() const { return value * 2; }
};

// ============================================================
// MAIN
// ============================================================
int main() {
    // TODO 17-21: demo code
    Point p(3, 4);
    p.display();
    std::cout << std::endl;

    Rectangle r1(0, 10, 5, 0);
    Rectangle r2(1, 8, 6, -2);

    r1.display();
    r2.display();

    std::cout << "Area r1: " << r1.getArea() << std::endl;
    std::cout << "Area r2: " << r2.getArea() << std::endl;

    std::cout << "Same size? "
              << (isSameSize(r1, r2) ? "Yes" : "No") << std::endl;

    ConstDemo cd(10);
    std::cout << "Value: " << cd.getValue() << std::endl;
    std::cout << "Const double: " << cd.constGetDouble() << std::endl;

    cd.doubleValue();
    std::cout << "After doubleValue: " << cd.getValue() << std::endl;

    return 0;
}
