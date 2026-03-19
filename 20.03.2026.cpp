//задание 1
//Задание 1 — Теоретические вопросы
//Что такое конструктор в C++?
//Это специальный метод класса, который автоматически вызывается при создании объекта для инициализации его.

//Когда вызывается конструктор объекта?
//При создании объекта класса — как на стеке, так и в динамической памяти.

//Что такое конструктор по умолчанию?
//Конструктор, который либо не принимает параметров, либо все параметры имеют значения по умолчанию.

//Можно ли создать несколько конструкторов в одном классе?
//Да, это называется перегрузкой конструкторов — несколько конструкторов с разными параметрами.

//Для чего используется деструктор?
//Для выполнения очистки перед уничтожением объекта (например, освобождение ресурсов).

//задание 2

#include <iostream>
using namespace std;

class Test {
public:
    Test() {
        cout << "Constructor called" << endl;
    }

    ~Test() {
        cout << "Destructor called" << endl;
    }
};

int main() {
    Test a;
    Test b;
    return 0;
}

//задание 3
#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    // Конструктор по умолчанию
    Student() : name("NoName"), age(0) {}

    // Конструктор с параметрами
    Student(string n, int a) : name(n), age(a) {}

    // Деструктор
    ~Student() {
        cout << "Destructor called for " << name << endl;
    }

    // Метод вывода информации
    void print() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main()
{
    Student s1;
    Student s2("Sasha", 20);

    s1.print();
    s2.print();

    return 0;
}

//задание 4
#include <iostream>
using namespace std;

class Book {
private:
    string title;
    int pages;

public:
    Book(string t, int p) : title(t), pages(p) {
        cout << "Book created" << endl;
    }

    ~Book() {
        cout << "Book deleted" << endl;
    }
};

int main() {
    Book b1("C++ Primer", 1000);
    Book b2("Clean Code", 464);

    return 0;
}

//задание 5 
#include <iostream>
using namespace std;

class Car {
private:
    string brand;
    int year;

public:
    // Конструктор по умолчанию
    Car() : brand("Unknown"), year(0) {}

    // Конструктор с параметрами
    Car(string b, int y) : brand(b), year(y) {}

    // Метод вывода информации
    void info() const {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

int main() {
    Car cars[3] = {
        Car("Toyota", 2020),
        Car("Ford", 2018),
        Car("Honda", 2022)
    };

    for (int i = 0; i < 3; ++i) {
        cars[i].info();
    }

    return 0;
}
