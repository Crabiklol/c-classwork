//1
#include <iostream>
using namespace std;

class Point {
private:
    int x;
    int y;
public:
    Point() : x(0), y(0) {} // конструктор по умолчанию
    void print() const {
        cout << "Point coordinates: " << x << " " << y << endl;
    }
};

int main() {
    Point p;
    p.print();
    return 0;
}

//2
#include <iostream>
using namespace std;

class Rectangle {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const { return width * height; }
    double perimeter() const { return 2 * (width + height); }
};

int main() {
    Rectangle rect(5, 10);
    cout << "Area: " << rect.area() << endl;
    cout << "Perimeter: " << rect.perimeter() << endl;
    return 0;
}

//3
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int age;
public:
    Student() : name("Unknown"), age(0) {}
    Student(string n, int a) : name(n), age(a) {}
    void print() const {
        cout << "Student: " << name << " " << age << endl;
    }
};

int main() {
    Student s1;
    Student s2("Ivan", 20);
    s1.print();
    s2.print();
    return 0;
}

//4
#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    int pages;
public:
    Book(string t, int p) : title(t), pages(p) {}
    void print() const {
        cout << "Book: " << title << ", Pages: " << pages << endl;
    }
};

int main() {
    Book b("C++ Programming", 300);
    b.print();
    return 0;
}


//5
#include <iostream>
using namespace std;

class Number {
private:
    int value;
public:
    Number(int v) : value(v) {}
    Number(const Number& other) : value(other.value) {}
    void print() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Number n1(10);
    Number n2 = n1;
    n1.print();
    n2.print();
    return 0;
}


//6
#include <iostream>
using namespace std;

class Test {
public:
    Test() { cout << "Object created" << endl; }
    ~Test() { cout << "Object destroyed" << endl; }
};

int main() {
    {
        Test t;
    } // здесь вызывается деструктор
    cout << "End of block" << endl;
    return 0;
}

//7
#include <iostream>
using namespace std;

class Array {
private:
    int* data;
public:
    Array() {
        data = new int[10];
        for (int i = 0; i < 10; ++i) {
            data[i] = i * 2;
        }
    }
    ~Array() { delete[] data; }
    void print() const {
        for (int i = 0; i < 10; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Array arr;
    arr.print();
    return 0;
}


//9
#include <iostream>
using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    int* data;
public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new int[rows * cols];
    }
    ~Matrix() { delete[] data; }
    void fill() {
        for (int i = 0; i < rows * cols; ++i) {
            data[i] = i;
        }
    }
    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i * cols + j] << "\t";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix m(3, 3);
    m.fill();
    m.print();
    return 0;
}

//10
#include <iostream>


#include <string>
using namespace std;

class BankAccount {
private:
    string owner;
    double balance;
public:
    BankAccount(string o, double b) : owner(o), balance(b) {}
    ~BankAccount() { cout << "Account closed" << endl; }
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        }
    }
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
        else {
            cout << "Insufficient funds or invalid amount" << endl;
        }
    }
    void printBalance() const {
        cout << "Owner: " << owner << ", Balance: " << balance << endl;
    }
};

int main() {
    BankAccount acc("John Doe", 1000.0);
    acc.printBalance();
    acc.deposit(500.0);
    acc.withdraw(200.0);
    acc.printBalance();
    return 0;
}
