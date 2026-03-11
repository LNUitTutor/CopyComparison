#include <iostream>
#include <vector>
#include "pVector.h"
#include "figures.h"

void print_vector(const char* title, const pVector<Figure*>& vect);

int main()
{
    pVector<Figure*> origin{ new Circle(), new Rectangle(), new Circle(2.), new Rectangle(2., 1.) };
    print_vector("--- The origin vector of figures", origin);
    pVector<Figure*> copy(origin);
    for (Figure* fig : copy) fig->scalingBy(2.);
    print_vector("\n--- The copy after scaling by 2.0", copy);
    print_vector("\n--- The origin after scaling copy by 2.0", origin);
}

void print_vector(const char* title, const pVector<Figure*>& vect)
{
    std::cout << title << '\n';
    for (Figure* fig : vect)
        std::cout << *fig << "\n  S = " << fig->area() << "   P = " << fig->perimeter() << '\n';
}