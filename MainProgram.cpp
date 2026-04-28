#include <iostream>
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
    Point(double x, double y) : x(x), y(y) {}

    double getX() const { return x; }
    double getY() const { return y; }

    void display() const {
        std::cout << "(" << x << "," << y << ")";
    }

    friend class Rectangle;
};

class Rectangle {
private:
    Point topLeft;
    Point bottomRight;

public:
    Rectangle(double x1, double y1, double x2, double y2)
        : topLeft(x1, y1), bottomRight(x2, y2) {}

    double getWidth() const {
        return std::abs(bottomRight.x - topLeft.x);
    }

    double getHeight() const {
        return std::abs(topLeft.y - bottomRight.y);
    }

    double getArea() const {
        return getWidth() * getHeight();
    }

    void display() const {
        topLeft.display();
        std::cout << " ";
        bottomRight.display();
        std::cout << " " << getArea() << std::endl;
    }

    friend bool isSameSize(const Rectangle& r1, const Rectangle& r2);
};

bool isSameSize(const Rectangle& r1, const Rectangle& r2) {
    return std::abs(r1.getWidth() - r2.getWidth()) < 1e-9 &&
           std::abs(r1.getHeight() - r2.getHeight()) < 1e-9;
}

class ConstDemo {
private:
    int value;

public:
    ConstDemo(int v) : value(v) {}

    int getValue() const { return value; }

    void doubleValue() {
        value *= 2;
    }

    int constGetDouble() const {
        return value * 2;
    }
};

// ============================================================
// MAIN
// ============================================================

int main() {
    Point p1(2, 3);
    p1.display();
    std::cout << std::endl;

    Rectangle r1(0, 10, 5, 0);
    Rectangle r2(1, 8, 6, -2);

    r1.display();
    r2.display();

    std::cout << (isSameSize(r1, r2) ? "1" : "0") << std::endl;

    ConstDemo cd(10);
    std::cout << cd.getValue() << std::endl;

    cd.doubleValue();
    std::cout << cd.getValue() << std::endl;

    std::cout << cd.constGetDouble() << std::endl;

    return 0;
}
