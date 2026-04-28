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

    public Vector(int x, int y) => (X, Y) = (x, y);

    // Перегрузка сложения
    public static Vector operator +(Vector left, Vector right) =>
        new Vector(left.X + right.X, left.Y + right.Y);

    // Перегрузка ==
    public static bool operator ==(Vector left, Vector right)
    {
        if (ReferenceEquals(left, right)) return true;
        if (left is null || right is null) return false;
        return left.X == right.X && left.Y == right.Y;
    }

    // Перегрузка !=
    public static bool operator !=(Vector left, Vector right) => !(left == right);

    // Рекомендовано при перегрузке ==/!=
    public override bool Equals(object obj) => obj is Vector v && this == v;
    public override int GetHashCode() => HashCode.Combine(X, Y);

    public override string ToString() => $"Vector({X}, {Y})";
}

class Program
{
    static void Main()
    {
        var v1 = new Vector(3, 4);
        var v2 = new Vector(1, 2);

        Vector sum = v1 + v2;
        Console.WriteLine($"Сумма: {sum}"); 

        Console.WriteLine($"v1 == v2: {v1 == v2}"); 
        Console.WriteLine($"v1 != v2: {v1 != v2}"); 

        var v3 = new Vector(3, 4);
        Console.WriteLine($"v1 == v3: {v1 == v3}"); 
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
        List<Order> orders = new()
        {
            new Order { Id = 1, Price = 50.0 },
            new Order { Id = 2, Price = 150.0 },
            new Order { Id = 3, Price = 200.0 },
            new Order { Id = 4, Price = 80.0 },
            new Order { Id = 5, Price = 300.0 }
        };

        // 1. Обработка пустой коллекции (дополнительно)
        if (!orders.Any())
        {
            Console.WriteLine("Коллекция заказов пуста.");
            return;
        }

        // 2. Агрегация
        double totalSum = orders.Sum(o => o.Price);
        double maxPrice = orders.Max(o => o.Price);
        double minPrice = orders.Min(o => o.Price);
        int countOver100 = orders.Count(o => o.Price > 100);

        Console.WriteLine($" Сумма заказов: {totalSum:F2}");
        Console.WriteLine($" Макс. цена: {maxPrice:F2}");
        Console.WriteLine($" Мин. цена: {minPrice:F2}");
        Console.WriteLine($" Заказов > 100: {countOver100}");

        // 3. Дополнительно: группировка по диапазонам цен
        var groupedByRange = orders.GroupBy(o => o.Price switch
        {
            < 100 => "Дешёвые (<100₽)",
            < 200 => "Средние (100-199₽)",
            _ => "Премиум (200₽+)"
        });

        Console.WriteLine("\n Группировка по диапазонам цен:");
        foreach (var group in groupedByRange)
        {
            double groupSum = group.Sum(x => x.Price);
            Console.WriteLine($"  {group.Key}: {group.Count()} шт. | Сумма: {groupSum:F2}₽");
        }
    }
}
                                                                                              
