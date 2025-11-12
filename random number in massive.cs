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
            const int size = 10;
            int[] arr = new int[size];
            Random rnd = new Random();
            for (int i = 0; i < arr.Length; i++)
            {
                arr[i] = rnd.Next(1, 10);
            }
            for (int i = 0; i < arr.Length; i++)
            {
                Console.WriteLine($"{arr[i]}");
            }
        }
    }
}
