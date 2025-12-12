using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp4
{
    class Student
    {
        public string firstName;
        public string lastName;
        public int age;
        public string gender;
        public double everageGrade;
        public double visiting;
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            Student std = new Student();//создание обьекта
            std.firstName = "Роман";//изменили поле firstName
            std.lastName = "Изотов";
            std.everageGrade = 5.01;
            std.visiting = 105.5;
            Console.WriteLine(std.firstName);
            Console.WriteLine(std.lastName);
            Console.WriteLine(std.everageGrade);
            Console.WriteLine(std.age);
        }

    }
}
