// ============================================================
// Lab: More Details about Classes
// Course: Object-Oriented Programming (C++)
// Level: 2nd Year Engineering
// Duration: 60 minutes
// ============================================================

#include <iostream>
#include <string>

// ============================================================
// CLASS DEFINITIONS
// ============================================================

class Point {
private:
    double x;
    double y;
public:
    // TODO 1: Constructor with member initializer list
    Point(double x, double y) : x(x), y(y) {}

    // TODO 2: const getter for x
    double getX() const { return x; }

    // TODO 3: const getter for y
    double getY() const { return y; }

    // TODO 4: const display()
    void display() const {
        std::cout << "(" << x << ", " << y << ")";
    }

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
    double getWidth() const {
        // Use direct member access via friend relationship
        return bottomRight.x - topLeft.x;
    }

    // TODO 8: const getHeight()
    double getHeight() const {
        return bottomRight.y - topLeft.y;
    }

    // TODO 9: const getArea()
    double getArea() const {
        return getWidth() * getHeight();
    }

    // TODO 10: const display()
    void display() const {
        std::cout << "Rectangle: topLeft=";
        topLeft.display();
        std::cout << ", bottomRight=";
        bottomRight.display();
        std::cout << ", width=" << getWidth()
                  << ", height=" << getHeight()
                  << ", area=" << getArea()
                  << std::endl;
    }

    // TODO 11: declare isSameSize as friend function
    friend bool isSameSize(const Rectangle& r1, const Rectangle& r2);
};


// TODO 12: implement isSameSize
bool isSameSize(const Rectangle& r1, const Rectangle& r2) {
    return (r1.getWidth() == r2.getWidth()) && (r1.getHeight() == r2.getHeight());
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
    void doubleValue() {
        value *= 2;
    }

    // TODO 16: const constGetDouble() — returns value * 2 without modifying
    int constGetDouble() const {
        return value * 2;
    }
};


// ============================================================
// MAIN
// ============================================================
int main() {
    // TODO 17: Demo Point
    std::cout << "=== Point Demo ===" << std::endl;
    Point p(3.0, 4.0);
    std::cout << "Point: ";
    p.display();
    std::cout << std::endl;
    std::cout << "getX(): " << p.getX() << ", getY(): " << p.getY() << std::endl;

    // TODO 18: Demo Rectangle
    std::cout << "\n=== Rectangle Demo ===" << std::endl;
    Rectangle r1(0.0, 0.0, 5.0, 3.0);
    r1.display();

    Rectangle r2(1.0, 1.0, 6.0, 4.0);
    r2.display();

    // TODO 19: Demo isSameSize
    std::cout << "\n=== isSameSize Demo ===" << std::endl;
    std::cout << "r1 and r2 same size? "
              << (isSameSize(r1, r2) ? "Yes" : "No") << std::endl;

    Rectangle r3(0.0, 0.0, 10.0, 7.0);
    r3.display();
    std::cout << "r1 and r3 same size? "
              << (isSameSize(r1, r3) ? "Yes" : "No") << std::endl;

    // TODO 20: Demo ConstDemo — const and non-const methods
    std::cout << "\n=== ConstDemo Demo ===" << std::endl;
    ConstDemo cd(5);
    std::cout << "Initial value: " << cd.getValue() << std::endl;
    std::cout << "constGetDouble(): " << cd.constGetDouble() << std::endl;

    cd.doubleValue();
    std::cout << "After doubleValue(): " << cd.getValue() << std::endl;

    // TODO 21: Verify const object can only call const methods
    const ConstDemo cdConst(10);
    std::cout << "\nconst ConstDemo value: " << cdConst.getValue() << std::endl;
    std::cout << "const ConstDemo constGetDouble(): " << cdConst.constGetDouble() << std::endl;
    // cdConst.doubleValue();  // Would NOT compile — correct behavior

    return 0;
}
