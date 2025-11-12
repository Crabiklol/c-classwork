using System;
using System.Collections.Generic;
using System.Diagnostics.Eventing.Reader;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp10
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Paste first number: ");
            Int32.TryParse(Console.ReadLine(), out int a);
            Console.WriteLine("Paste second number: ");
            Int32.TryParse(Console.ReadLine(), out int b);
            Console.WriteLine("Enter a symbol (*,/,+,-)");
            char.TryParse(Console.ReadLine(), out char c);
            if (c == '-')
            {
                Console.WriteLine(a - b);
            }
            else if (c == '+')
            {
                Console.WriteLine(a + b);
            }
            else if (c == '*')
            {
                Console.WriteLine(a * b);
            }
            else if (c == '/')
            {

                if (b != 0)
                {
                    Console.WriteLine($"Результат: {a / (double)b}");
                }
                else
                {
                    Console.WriteLine("Ошибка: деление на ноль!");
                }
            }
            else
            {
                Console.WriteLine("error operation");
            }

        }
    }
}
