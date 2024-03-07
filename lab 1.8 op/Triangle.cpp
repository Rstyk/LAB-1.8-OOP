#include "Triangle.h"
#include <cmath>
#include <string>
using namespace std;

bool Triangle::Point::init(double a, double b)
{
    setX(a);
    setY(b);
    return true;
}

string Triangle::Point::toString()
{
    stringstream sout;
    sout << x << y;
    return sout.str();
}

void Triangle::Point::read()
{
    int a, b;
    do
    {
        std::cout << "x =  ";
        std::cin >> a;
        std::cout << "y =  ";
        std::cin >> b;
    } while (!init(a, b));
}

void Triangle::Point::display() const
{
    std::cout << std::endl;
    std::cout << "x = " << getX() << std::endl;
    std::cout << "y = " << getY() << std::endl;
    std::cout << std::endl;
}

double Triangle::Point::distanceToOrigin() const
{
    double result = sqrt(x * x + y * y);
    return result;
}

void Triangle::Point::polarizeCoords()
{
    double dist = distanceToOrigin();
    double angle = acos(1.0 * x / dist);
    setX(dist);
    setY(angle);
}

double distanceOfPoints(Triangle::Point p1, Triangle::Point p2)
{
    double x1 = p1.getX();
    double y1 = p1.getY();
    double x2 = p2.getX();
    double y2 = p2.getY();

    double dx = x1 - x2;
    double dy = y1 - y2;
    double result = sqrt(dx * dx + dy * dy);
    return result;
}

bool equalityPoints(Triangle::Point p1, Triangle::Point p2)
{
    if (p1.getX() == p2.getX() && p1.getY() == p2.getY())
        return true;
    else
        return false;
}

void Triangle::displayTriangle() const
{
    std::cout << std::endl;
    std::cout << "First point P1 (A)" << std::endl;
    P1.display();
    std::cout << "Second point P2 (B)" << std::endl;
    P2.display();
    std::cout << "Third point P3 (C)" << std::endl;
    P3.display();
    std::cout << "P1P2 (AB) = " << get_a() << std::endl;
    std::cout << "P2P3 (BC) = " << get_b() << std::endl;
    std::cout << "P1P3 (AC) = " << get_c() << std::endl;
    std::cout << std::endl;
}

void Triangle::readTriangle()
{
    std::cout << "First point P1 (A)" << std::endl;
    P1.read();
    std::cout << "Second point P2 (B)" << std::endl;
    P2.read();
    std::cout << "Third point P3 (C)" << std::endl;
    P3.read();
}

void Triangle::init(double x1, double y1, double x2, double y2, double x3, double y3)
{
    P1.setX(x1);
    P1.setY(y1);
    P2.setX(x2);
    P2.setY(y2);
    P3.setX(x3);
    P3.setY(y3);
}

double Triangle::get_a() const
{
    return distanceOfPoints(P1, P2);
}

double Triangle::get_b() const
{
    return distanceOfPoints(P2, P3);
}

double Triangle::get_c() const
{
    return distanceOfPoints(P1, P3);
}

double Triangle::get_A() const
{
    double a = get_a();
    double b = get_b();
    double c = get_c();

    double cosA = (a * a + c * c - b * b) / (2 * a * c);
    return acos(cosA);
}

double Triangle::get_B() const
{
    double a = get_a();
    double b = get_b();
    double c = get_c();

    double cosB = (a * a + b * b - c * c) / (2 * a * b);
    return acos(cosB);
}

double Triangle::get_C() const
{
    double a = get_a();
    double b = get_b();
    double c = get_c();

    double cosC = (b * b + c * c - a * a) / (2 * b * c);
    return acos(cosC);
}

double Triangle::hA() const
{
    double p = perimeter() / 2;
    double S = square();
    return 2 * S / get_b();
}

double Triangle::hB() const
{
    double p = perimeter() / 2;
    double S = square();
    return 2 * S / get_c();
}

double Triangle::hC() const
{
    double p = perimeter() / 2;
    double S = square();
    return 2 * S / get_a();
}

double Triangle::perimeter() const
{
    return get_a() + get_b() + get_c();
}

string Triangle::triangleType() const
{
    string result;
    double a = get_a();
    double b = get_b();
    double c = get_c();
    double angle_a, angle_b, angle_c;
    angle_a = get_A();
    angle_b = get_B();
    angle_c = get_C();

    if (a == b && b == c)
        result = "Equilateral triangle";
    else if (a == b || a == c || b == c) {
        if (sin(angle_a) == 1.0 || sin(angle_b) == 1.0 || sin(angle_c) == 1.0)
            result = "Right-angled isosceles triangle";
        else
            result = "Isosceles triangle";
    }
    else if (sin(angle_a) == 1.0 || sin(angle_b) == 1.0 || sin(angle_c) == 1.0)
        result = "Right-angled triangle";
    else
        result = "Scalene triangle ";

    return result;
}

double Triangle::square() const
{
    double halfPerimeter = perimeter() / 2;
    double a = get_a();
    double b = get_b();
    double c = get_c();
    return sqrt(halfPerimeter * (halfPerimeter - a) * (halfPerimeter - b) * (halfPerimeter - c));
}

