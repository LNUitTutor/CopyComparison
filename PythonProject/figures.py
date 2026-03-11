from abc import ABC, abstractmethod
import math

class Figure(ABC):
    @abstractmethod
    def area(self):
        pass
    @abstractmethod
    def perimeter(self):
        pass
    @abstractmethod
    def scalingBy(self, coef):
        pass

class Circle(Figure):
    def __init__(self, r = 1.0):
        self.radius = r if r > 0 else 0.1

    def __str__(self):
        return f'Circle({self.radius})'

    def area(self):
        return math.pi * self.radius ** 2

    def perimeter(self):
        return 2.0 * math.pi * self.radius

    def scalingBy(self, coef):
        if (coef <= 0.0):
            coef = 0.1
        self.radius *= coef
        return self

class Rectangle(Figure):
    def __init__(self, a = 3.0, b = 4.0):
        self.length = a if a > 0 else 0.1
        self.width = b if b > 0 else 0.1

    def __str__(self):
        return f'Rectangle[{self.length}x{self.width}]'

    def area(self):
        return self.length * self.width

    def perimeter(self):
        return 2.0 * (self.length + self.width)

    def scalingBy(self, coef):
        if (coef <= 0.0):
            coef = 0.1
        self.length *= coef
        self.width *= coef
        return self
