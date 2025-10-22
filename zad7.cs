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
                int a = int.Parse(Console.ReadLine());

                Console.Write("Введите число b: ");
                int b = int.Parse(Console.ReadLine());

                  
                int sum = 0;


                if (a < b)
                {
                     
                    for (int i = a; i < b; i++)
                    {
                        sum += i;
                    }
                }   
                Console.WriteLine($"Сумма чисел от {a} до {b} равна: {sum}");
            }

        }
        
    }
}
