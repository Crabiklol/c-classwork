using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp10
{
    internal class Program
    {
        static void Main(string[] args)
        {
            
            {
               
                Console.Write("Введите целое число n: ");
                int n = int.Parse(Console.ReadLine());

               
                double factorial = 1.0;

                
                for (int i = 1; i <= n; i++)
                {
                    factorial *= i;
                }
                Console.WriteLine($"Факториал числа {n} равен: {factorial}");
            }
        }
    }
}
