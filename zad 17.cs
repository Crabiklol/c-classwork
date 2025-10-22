using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp9
{
    internal class Program
    {
        static void Main(string[] args)
        {
            {
                Console.Write("Введите число a: ");
                double a = double.Parse(Console.ReadLine());

                Console.Write("Введите число b: ");

                int b = int.Parse(Console.ReadLine());
                double result = 1;
                for (int i = 0; i < b; i++)
                {
                    result *= a;
                }
                Console.WriteLine($"{a} в степени {b} равно {result}");

            }
        }
    }
}
