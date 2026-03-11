#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
class Figure abstract
{
public:
	virtual ~Figure() { }
	virtual double area() const abstract;
	virtual double perimeter() const abstract;
	virtual void printOn(std::ostream& os) const abstract;
	virtual Figure& scalingBy(double coef) abstract;
	virtual Figure* clone() const abstract;
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