#include <iostream>
#include <string>

// ============================================================
// CLASS DEFINITIONS
// ============================================================

class Rectangle; // forward declaration for friend

class Point {
private:
    double x;
    double y;

public:
    // TODO 1
    Point(double x, double y) : x(x), y(y) {}

    // TODO 2
    double getX() const { return x; }

    // TODO 3
    double getY() const { return y; }

    // TODO 4
    void display() const {
        std::cout << "(" << x << ", " << y << ")";
    }

    // TODO 5
    friend class Rectangle;
};

class Rectangle {
private:
    Point topLeft;
    Point bottomRight;

public:
    // TODO 6
    Rectangle(double x1, double y1, double x2, double y2)
        : topLeft(x1, y1), bottomRight(x2, y2) {}

    // TODO 7
    double getWidth() const {
        return std::abs(bottomRight.x - topLeft.x);
    }

    // TODO 8
    double getHeight() const {
        return std::abs(topLeft.y - bottomRight.y);
    }

    // TODO 9
    double getArea() const {
        return getWidth() * getHeight();
    }

    // TODO 10
    void display() const {
        std::cout << "TopLeft: ";
        topLeft.display();
        std::cout << ", BottomRight: ";
        bottomRight.display();
        std::cout << ", Area: " << getArea() << std::endl;
    }

    // TODO 11
    friend bool isSameSize(const Rectangle& r1, const Rectangle& r2);
};

// TODO 12
bool isSameSize(const Rectangle& r1, const Rectangle& r2) {
    return (r1.getWidth() == r2.getWidth()) &&
           (r1.getHeight() == r2.getHeight());
}

class ConstDemo {
private:
    int value;

public:
    // TODO 13
    ConstDemo(int v) : value(v) {}

    // TODO 14
    int getValue() const { return value; }

    // TODO 15
    void doubleValue() {
        value *= 2;
    }

    // TODO 16
    int constGetDouble() const {
        return value * 2;
    }
};

// ============================================================
// MAIN
// ============================================================

int main() {
    // TODO 17-21

    Point p1(2, 3);
    p1.display();
    std::cout << std::endl;

    Rectangle r1(0, 10, 5, 0);
    Rectangle r2(1, 8, 6, -2);

    r1.display();
    r2.display();

    std::cout << "Same size? "
              << (isSameSize(r1, r2) ? "Yes" : "No") << std::endl;

    ConstDemo cd(10);
    std::cout << "Value: " << cd.getValue() << std::endl;

    cd.doubleValue();
    std::cout << "After doubleValue(): " << cd.getValue() << std::endl;

    std::cout << "constGetDouble(): " << cd.constGetDouble() << std::endl;

    return 0;
}
