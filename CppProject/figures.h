#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
class Figure
{
public:
	virtual ~Figure() { }
	virtual double area() const = 0;
	virtual double perimeter() const = 0;
	virtual void printOn(std::ostream& os) const = 0;
	virtual Figure& scalingBy(double coef) = 0;
	virtual Figure* clone() const = 0;
};
std::ostream& operator<<(std::ostream& os, const Figure& fig);

class Circle :public Figure
{
private:
	double radius;
public:
	Circle() :radius(1.) { }
	Circle(double r);
	~Circle();
	virtual double area() const override;
	virtual double perimeter() const override;
	virtual void printOn(std::ostream& os) const override;
	virtual Circle& scalingBy(double coef) override;
	virtual Circle* clone() const override;
};

class Rectangle :public Figure
{
private:
	double length, width;
public:
	Rectangle() :length(3.), width(4.) { }
	Rectangle(double a, double b);
	~Rectangle();
	virtual double area() const override;
	virtual double perimeter() const override;
	virtual void printOn(std::ostream& os) const override;
	virtual Rectangle& scalingBy(double coef) override;
	virtual Rectangle* clone() const override;
};