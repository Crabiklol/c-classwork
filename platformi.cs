//1 zadanie
using System;

class Program
{
    static void Main()
    {
     
        Predicate<string> isNotNullOrEmpty = s => !string.IsNullOrEmpty(s);

        
        Predicate<int> isInRange = num => num >= 1 && num <= 100;

      
        bool Validate<T>(T value, Predicate<T> predicate)
        {
            return predicate(value);
        }

        
        string testString1 = "Hello";
        string testString2 = "";
        int testNumber1 = 50;
        int testNumber2 = 150;

        Console.WriteLine($"Проверка строки '{testString1}': {Validate(testString1, isNotNullOrEmpty)}");
        Console.WriteLine($"Проверка строки '{testString2}': {Validate(testString2, isNotNullOrEmpty)}");
        Console.WriteLine($"Проверка числа {testNumber1}: {Validate(testNumber1, isInRange)}");
        Console.WriteLine($"Проверка числа {testNumber2}: {Validate(testNumber2, isInRange)}");
    }
}

//2 zadanie
using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
     
        List<int> numbers = new List<int> { 1, 2, 3, 4, 5 };

       
        Func<int, int> square = n => n * n;

       
        Action<int> print = n => Console.WriteLine($"Результат: {n}");

     
        var squaredNumbers = numbers.Select(square).ToList();

    
        foreach (var num in squaredNumbers)
        {
            print(num);
        }
    }
}
