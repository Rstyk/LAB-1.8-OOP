#include <sstream>
#pragma once
#include <iostream>
#include <string>
using namespace std;
class Triangle
{
public:
    class Point
    {
    private:
        double x, y;

    public:
        double getX() const { return x; }
        void setX(double value) { x = value; }
        double getY() const { return y; }
        void setY(double value) { y = value; }

        bool init(double a, double b);
        std::string toString();
        void read();
        void display() const;

        double distanceToOrigin() const;
        void moveX(double value) { setX(x + value); }
        void moveY(double value) { setY(y + value); }
        void polarizeCoords();

        friend double distanceOfPoints(Point p1, Point p2);
        friend bool equalityPoints(Point p1, Point p2);
    };

    Point P1, P2, P3;

public:
    void displayTriangle() const;
    void readTriangle();
    void init(double x1, double y1, double x2, double y2, double x3, double y3);

    double get_a() const;
    double get_b() const;
    double get_c() const;

    double get_A() const;
    double get_B() const;
    double get_C() const;

    double hA() const;
    double hB() const;
    double hC() const;

    double perimeter() const;
    std::string triangleType() const;
    double square() const;
};

