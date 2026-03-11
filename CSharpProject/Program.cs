using System;
using System.Collections.Generic;

namespace CSharpProject
{
    class Program
    {
        static void Main(string[] args)
        {
            List<Figure> origin = new() { new Circle(), new Rectangle(), new Circle(2.0), new Rectangle(2.0, 1.0) };
            PrintList("--- The origin list of figures", origin);
            List<Figure> copy = origin.ConvertAll(book => book.Clone());
            foreach (Figure fig in copy) fig.scalingBy(2.0);
            PrintList("\n--- The copy after scaling by 2.0", copy);
            PrintList("\n--- The origin after scaling copy by 2.0", origin);
        }
        static void PrintList(string title, List<Figure> list)
        {
            Console.WriteLine(title);
            foreach (Figure fig in list)
                Console.WriteLine($"{fig}\n  S = {fig.area()}   P = {fig.perimeter()}");
        }
    }
}