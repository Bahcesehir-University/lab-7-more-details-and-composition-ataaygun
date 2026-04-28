// ============================================================
// Lab: More Details about Classes
// Course: Object-Oriented Programming (C++)
// Level: 2nd Year Engineering
// Duration: 60 minutes
// ============================================================

#include <iostream>
#include <string>
#include <cmath> // std::abs kullanabilmek için eklendi

// ============================================================
// CLASS DEFINITIONS
// ============================================================

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
    double getWidth() const { 
        // Point sınıfının friend'i olduğu için x'e direkt erişilebilir
        return std::abs(bottomRight.x - topLeft.x); 
    }

    // TODO 8: const getHeight()
    double getHeight() const { 
        // Point sınıfının friend'i olduğu için y'ye direkt erişilebilir
        return std::abs(topLeft.y - bottomRight.y); 
    }

    // TODO 9: const getArea()
    double getArea() const { 
        return getWidth() * getHeight(); 
    }

    // TODO 10: const display()
    void display() const {
        std::cout << "Top Left: ";
        topLeft.display();
        std::cout << ", Bottom Right: ";
        bottomRight.display();
    }

    // TODO 11: declare isSameSize as friend function
    friend bool isSameSize(const Rectangle& r1, const Rectangle& r2);
};


// TODO 12: implement isSameSize
bool isSameSize(const Rectangle& r1, const Rectangle& r2) {
    return r1.getArea() == r2.getArea();
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
    
    // 17 & 18. Rectangle (ve dolaylı olarak Point) oluşturma
    Rectangle rect1(0, 10, 5, 0); // Genişlik: 5, Yükseklik: 10, Alan: 50
    Rectangle rect2(0, 5, 10, 0); // Genişlik: 10, Yükseklik: 5, Alan: 50
    Rectangle rect3(0, 4, 4, 0);  // Genişlik: 4, Yükseklik: 4, Alan: 16

    // 19. Alan yazdırma ve display() testleri
    std::cout << "--- Rectangle 1 ---" << std::endl;
    rect1.display();
    std::cout << "\nArea: " << rect1.getArea() << std::endl;

    std::cout << "\n--- Rectangle 2 ---" << std::endl;
    rect2.display();
    std::cout << "\nArea: " << rect2.getArea() << std::endl;

    // 20. isSameSize() fonksiyonunu test etme
    std::cout << "\n--- Size Comparison ---" << std::endl;
    std::cout << "Is rect1 same size as rect2? " << (isSameSize(rect1, rect2) ? "Yes" : "No") << std::endl;
    std::cout << "Is rect1 same size as rect3? " << (isSameSize(rect1, rect3) ? "Yes" : "No") << std::endl;

    // 21. ConstDemo testleri
    std::cout << "\n--- ConstDemo Tests ---" << std::endl;
    ConstDemo demo(10);
    std::cout << "Initial Value (getValue): " << demo.getValue() << std::endl;
    std::cout << "constGetDouble() result: " << demo.constGetDouble() << std::endl;
    std::cout << "Value after constGetDouble (should be unchanged): " << demo.getValue() << std::endl;
    
    demo.doubleValue();
    std::cout << "Value after doubleValue() call: " << demo.getValue() << std::endl;

    return 0;
}
