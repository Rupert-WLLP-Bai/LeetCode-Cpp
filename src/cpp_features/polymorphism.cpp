// 关于多态
#include "core.h"
using namespace std;

// 1. 函数重载
class A {
  public:
    void func() {
        cout << "A::func()" << endl;
    }

    void func(int a) {
        cout << "A::func(int a)" << endl;
    }
};

// 2. 虚函数
class Shape {
  public:
    virtual double calcArea() {
        cout << "Shape::calcArea()" << endl;
        return 0;
    }
    virtual ~Shape() {
        cout << "Shape::~Shape()" << endl;
    }
};

class Circle : public Shape {
  public:
    Circle(double r) : radius(r) {
    }
    virtual double calcArea() {
        cout << "Circle::calcArea()" << endl;
        return 3.14 * radius * radius;
    }
    virtual ~Circle() {
        cout << "Circle::~Circle()" << endl;
    }

  private:
    double radius;
};

class Rectangle : public Shape {
  public:
    Rectangle(double l, double w) : length(l), width(w) {
    }
    virtual double calcArea() {
        cout << "Rectangle::calcArea()" << endl;
        return length * width;
    }
    virtual ~Rectangle() {
        cout << "Rectangle::~Rectangle()" << endl;
    }

  private:
    double length;
    double width;
};

void shapeTest() {
    Shape *shape = new Circle(10);
    cout << "Area = " << shape->calcArea() << endl;
    delete shape;

    shape = new Rectangle(10, 20);
    cout << "Area = " << shape->calcArea() << endl;
    delete shape;
}

int main() {
    shapeTest();
    return 0;
}