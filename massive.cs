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
            for (int i = 0; i< size; i++)
            {
                arr[i] = i;

            }
            for (int i = 0; i < size; i++)
            {
                Console.WriteLine($"{arr[i]}");
            }
        }
    }
}
