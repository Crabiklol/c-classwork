Теоретическая часть
1 Перегрузка операторов в C#

 Перегрузка операторов  ====== 
 Возможность задать собственное поведение
 стандартных операторов (+, -, == и др.)
 для пользовательских типов, делая код более
  читаемым и естественным.

  
 Синтаксис перегрузки (operator) ============
 public static ТипВозврата operator СимволОператора(Параметры).
  Оператор всегда static и public. 
  Возвращаемый тип и параметры зависят от оператора.

  
 Какие операторы можно перегружать ==============
 Арифметические (+ - * / %), унарные (+ - ! ~ ++ --), сравнения (== != < > <= >=), логические (`&

                                                                                               
 Правила и ограничения ============
 Нельзя перегружать: =, &&,


                                                                                               
 Примеры практического применения ============
 Математические векторы/матрицы, денежные суммы с валютой,
 сложные даты/интервалы, игровые координаты, доменные модели 
(например, OrderItem + OrderItem).                                                                                              
 
2 Наследование и полиморфизм


 Базовый и производный классы =========
 class Derived : Base. Производный класс наследует public/protected члены, методы и свойства.
 Конструкторы не наследуются, но вызываются через base().  

                                                                                               
 ключевое слово base =============
 Вызывает конструктор базового класса: base(param).
 Доступ к перекрытым/переопределённым членам: base.Method().

                                                                                               
 виртуальные методы (virtual.override) ================
 virtual помечает метод как переопределяемый. override заменяет реализацию в наследнике, 
 сохраняя полиморфное поведение на этапе выполнения.

                                                                                               
 полиморфизм (переопределение методов) =============
 Один интерфейс/базовый тип, множество реализаций. 
 Вызов метода определяется фактическим типом объекта в runtime, а не типом ссылки.
                                                                                               
 отличие override от new =================
 override → переопределяет, полиморфизм работает.
 new → скрывает член базового класса, вызов зависит от типа ссылки (compile-time), полиморфизм теряется.
 
                                                                                               
 примеры использования =============
 Система фигур (Shape → Circle, Rectangle), обработка сотрудников (Employee → Manager, Developer), паттерн "Стратегия".

                                                                                               
 3 LINQ (агрегация и продвинутые операции)
                                                                                               
 Агрегирующие методы: ================
    Count()
    Sum()
    Average()
    Min() / Max()
  Count() – количество элементов. Sum() – сумма.
  Average() – среднее (бросает InvalidOperationException на пустой коллекции для int).
  Min()/Max() – минимум/максимум.           

                                                                                               
 Группировка (Group by) ============
 Группирует элементы по ключу. Возвращает IEnumerable<IGrouping<TKey, TElement>>.
 Часто используется с Select для агрегации внутри групп.

                                                                                               
 Выбор первого элемента (First, FirstOrDefault) ============
 First() возвращает первый элемент или бросает исключение, если коллекция пуста.
 FirstOrDefault() возвращает первый элемент или default(T) (null для классов, 0 для int и т.д.).


                                                                                               
 Отличие First и FirstOrDefault =================
 First → строгий, используется когда элемент гарантированно существует.
 FirstOrDefault → безопасный, требует проверки на default/null после вызова.

                                                                                               
 Примеры практического применения ===============
 Финансовые отчёты, статистика, поиск первой подходящей записи, группировка товаров/пользователей по категориям или диапазонам.

                                                                                               
 Практическое задание 
 Задание 1

using System;

class Vector
{
    public int X { get; set; }
    public int Y { get; set; }

    public Vector(int x, int y)
    {
        X = x;
        Y = y;
    }

    public static Vector operator +(Vector a, Vector b)
    {
        return new Vector(a.X + b.X, a.Y + b.Y);
    }

    public static bool operator ==(Vector a, Vector b)
    {
        return a.X == b.X && a.Y == b.Y;
    }

    public static bool operator !=(Vector a, Vector b)
    {
        return !(a == b);
    }
}

class Program
{
    static void Main()
    {
    
        Vector v1 = new Vector(2, 3);
        Vector v2 = new Vector(4, 5);

      
        Vector sum = v1 + v2;
        Console.WriteLine($"v1 + v2 = ({sum.X}, {sum.Y})");

     
        Console.WriteLine($"v1 == v2: {v1 == v2}");
        Console.WriteLine($"v1 != v2: {v1 != v2}");
    }
}



Задание 2
using System;
using System.Collections.Generic;
using System.Linq;

class Order
{
    public int Id { get; set; }
    public double Price { get; set; }
}

class Program
{
    static void Main()
    {
        
        List<Order> orders = new List<Order>
        {
            new Order { Id = 1, Price = 80 },
            new Order { Id = 2, Price = 150 },
            new Order { Id = 3, Price = 90 },
            new Order { Id = 4, Price = 200 },
            new Order { Id = 5, Price = 110 }
        };

       
        double total = orders.Sum(o => o.Price);
        Console.WriteLine($"Сумма всех заказов: {total}");

        
        double maxPrice = orders.Max(o => o.Price);
        Console.WriteLine($"Максимальная цена: {maxPrice}");

        
        Order minOrder = orders.First(o => o.Price == orders.Min(x => x.Price));
        Console.WriteLine($"Заказ с минимальной ценой: Id={minOrder.Id}, Price={minOrder.Price}");

        
        int countOver100 = orders.Count(o => o.Price > 100);
        Console.WriteLine($"Количество заказов дороже 100: {countOver100}");

       
        Console.WriteLine("\nГруппировка по диапазонам цен:");
        var groups = orders.GroupBy(o =>
            o.Price < 100 ? "До 100" :
            o.Price <= 200 ? "100–200" : "Больше 200");

        foreach (var group in groups)
        {
            Console.WriteLine($"{group.Key}: {group.Count()} заказов");
        }

        
        List<Order> emptyOrders = new List<Order>();
        double emptySum = emptyOrders.Sum(o => o.Price); 
        Console.WriteLine($"\nСумма пустой коллекции: {emptySum}");
    }
}

