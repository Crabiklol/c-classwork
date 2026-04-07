using System;
using System.Collections.Generic;


public abstract class Animal
{
    public string Name { get; set; }
    public int Age { get; set; }
    public double Weight { get; set; }

    public Animal(string name, int age, double weight)
    {
        Name = name;
        Age = age;
        Weight = weight;
    }

    public abstract void MakeSound();

    public virtual void DisplayInfo()
    {
        Console.WriteLine($"{Name} (возраст: {Age}, вес: {Weight} кг)");
    }
}


public class Mammal : Animal
{
    public Mammal(string name, int age, double weight) : base(name, age, weight) { }

    public override void MakeSound()
    {
        Console.WriteLine($"{Name} говорит: Муу");
    }
}

public class Bird : Animal
{
    public Bird(string name, int age, double weight) : base(name, age, weight) { }

    public override void MakeSound()
    {
        Console.WriteLine($"{Name} говорит: Ку-ку");
    }
}

public class Reptile : Animal
{
    public Reptile(string name, int age, double weight) : base(name, age, weight) { }

    public override void MakeSound()
    {
        Console.WriteLine($"{Name} шипит");
    }
}


public class Zoo
{
    private List<Animal> animals = new List<Animal>();

    public void AddAnimal(Animal animal)
    {
        animals.Add(animal);
        Console.WriteLine($"Добавлено: {animal.Name}");
    }

    public void ShowAnimals()
    {
        Console.WriteLine("Все животные в зоопарке:");
        foreach (var animal in animals)
        {
            animal.DisplayInfo();
        }
    }

    public void AnimalsMakeSounds()
    {
        Console.WriteLine("Звуки животных:");
        foreach (var animal in animals)
        {
            animal.MakeSound();
        }
    }

    public void FeedAnimals()
    {
        Console.WriteLine("Кормим животных:");
        foreach (var animal in animals)
        {
            Console.WriteLine($"{animal.Name} накормлен(а).");
        }
    }
}

class Program
{
    static void Main()
    {
       
        Zoo zoo = new Zoo();

      
        zoo.AddAnimal(new Mammal("Лев", 4, 190));
        zoo.AddAnimal(new Bird("Попугай", 2, 1));
        zoo.AddAnimal(new Reptile("Кобра", 3, 4));

        
        zoo.ShowAnimals();

        
        zoo.AnimalsMakeSounds();

       
        zoo.FeedAnimals();

        Console.ReadLine();
    }
}
