//1
#include <iostream>
using namespace std;

class Vehicle {
protected:
    int speed;
public:
    Vehicle(int s) : speed(s) {}
    virtual void move() {
        cout << "Vehicle moves at speed " << speed << endl;
    }
};

class Car : public Vehicle {
public:
    Car(int s) : Vehicle(s) {}
    void honk() {
        cout << "Car honks: Beep beep!\n";
    }
};

class Bicycle : public Vehicle {
public:
    Bicycle(int s) : Vehicle(s) {}
    void ringBell() {
        cout << "Bicycle rings bell: Ring ring!\n";
    }
};

int main() {
    Car car(60);
    Bicycle bike(15);
    
    car.move();
    bike.move();
    
    car.honk();
    bike.ringBell();

    return 0;
}

//2
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() {
        cout << "Animal makes sound\n";
    }
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog barks\n";
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Cat meows\n";
    }
};

int main() {
    Animal* animals[2];
    animals[0] = new Dog();
    animals[1] = new Cat();
    
    for (int i = 0; i < 2; i++) {
        animals[i]->sound();
    }
    
    // Очистка памяти
    for (int i = 0; i < 2; i++) {
        delete animals[i];
    }

    return 0;
}

//3
#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;  // чисто виртуальная
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return M_PI * radius * radius;
    }
};

int main() {
    Shape* shapes[2];
    shapes[0] = new Rectangle(4, 5);
    shapes[1] = new Circle(3);

    for (int i = 0; i < 2; i++) {
        cout << "Area: " << shapes[i]->area() << endl;
    }

    // Очистка памяти
    for (int i = 0; i < 2; i++) {
        delete shapes[i];
    }

    return 0;
}

//4
#include <iostream>
using namespace std;

class Character {
public:
    virtual void attack() = 0;
    virtual ~Character() = default;
};

class Warrior : public Character {
public:
    void attack() override {
        cout << "Warrior attacks with sword\n";
    }
};

class Mage : public Character {
public:
    void attack() override {
        cout << "Mage casts spell\n";
    }
};

int main() {
    Character* characters[2];
    characters[0] = new Warrior();
    characters[1] = new Mage();
    
    for (int i = 0; i < 2; i++) {
        characters[i]->attack();
    }

    // Очистка памяти
    for (int i = 0; i < 2; i++) {
        delete characters[i];
    }

    return 0;
}

//5
#include <iostream>
using namespace std;

class BankAccount {
protected:
    double balance;
public:
    BankAccount(double b) : balance(b) {}
    virtual double calculateInterest() = 0;  // виртуальная функция
    virtual ~BankAccount() = default;
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(double b) : BankAccount(b) {}
    double calculateInterest() override {
        return balance * 0.05;
    }
};

class CurrentAccount : public BankAccount {
public:
    CurrentAccount(double b) : BankAccount(b) {}
    double calculateInterest() override {
        return balance * 0.02;
    }
};

int main() {
    SavingsAccount s(1000);
    CurrentAccount c(1000);
    
    BankAccount* accounts[2];
    accounts[0] = &s;
    accounts[1] = &c;
    
    for (int i = 0; i < 2; i++) {
        cout << "Interest: " << accounts[i]->calculateInterest() << endl;
    }

    return 0;
}
