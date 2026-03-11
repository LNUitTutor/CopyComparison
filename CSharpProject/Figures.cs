using System;

namespace CSharpProject
{
    abstract class Figure /*: ICloneable*/
    {
        public abstract double area();
        public abstract double perimeter();
        public abstract Figure scalingBy(double coef);
        public abstract Figure Clone();
    }
    class Circle : Figure
    {
        private double radius;
        public Circle()
        {
            radius = 1.0;
        }
        public Circle(double r)
        {
            radius = r > 0.0 ? r : 0.1;
        }
        public override double area()
        {
            return Math.PI * radius * radius;
        }
        public override double perimeter()
        {
            return 2.0 * Math.PI * radius;
        }
        public override Circle scalingBy(double coef)
        {
            if (coef <= 0.0) coef = 0.1;
            radius *= coef;
            return this;
        }
        public override Circle Clone()
        {
            return new Circle(this.radius);
        }
        public override string ToString()
        {
            return $"Circle({radius})";
        }
    }
    class Rectangle : Figure
    {
        private double length, width;
        public Rectangle()
        {
            length = 3.0;
            width = 4.0;
        }
        public Rectangle(double a, double b)
        {
            length = a > 0.0 ? a : 0.1;
            width = b > 0.0 ? b : 0.1;
        }
        public override double area()
        {
            return length * width;
        }
        public override double perimeter()
        {
            return 2.0 * (length + width);
        }
        public override Rectangle scalingBy(double coef)
        {
            if (coef <= 0.0) coef = 0.1;
            length *= coef;
            width *= coef;
            return this;
        }
        public override Rectangle Clone()
        {
            return new Rectangle(this.length, this.width);
        }
        public override string ToString()
        {
            return $"Rectangle[{length}x{width}]";
        }
    }
}
