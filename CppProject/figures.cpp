#include "figures.h"

std::ostream& operator<<(std::ostream& os, const Figure& fig)
{
	fig.printOn(os);
	return os;
}

Circle::Circle(double r)
{
	radius = r > 0. ? r : 0.1;
}

Circle::~Circle()
{
	std::cout << *this << " said 'Bye!'\n";
}

double Circle::area() const
{
	return M_PI * radius * radius;
}

double Circle::perimeter() const
{
	return 2.0 * M_PI * radius;
}

void Circle::printOn(std::ostream& os) const
{
	os << "Circle(" << radius << ')';
}

Circle& Circle::scalingBy(double coef)
{
	if (coef <= 0.) coef = 0.1;
	radius *= coef;
	return *this;
}

Circle* Circle::clone() const
{
	return new Circle(*this);
}

Rectangle::Rectangle(double a, double b)
{
	length = a > 0. ? a : 0.1;
	width = b > 0. ? b : 0.1;
}

Rectangle::~Rectangle()
{
	std::cout << *this << " said 'Bye!'\n";
}

double Rectangle::area() const
{
	return length * width;
}

double Rectangle::perimeter() const
{
	return 2.0 * (length + width);
}

void Rectangle::printOn(std::ostream& os) const
{
	os << "Rectangle[" << length << 'x' << width << ']';
}

Rectangle& Rectangle::scalingBy(double coef)
{
	if (coef <= 0.) coef = 0.1;
	length *= coef;
	width *= coef;
	return *this;
}

Rectangle* Rectangle::clone() const
{
	return new Rectangle(*this);
}
