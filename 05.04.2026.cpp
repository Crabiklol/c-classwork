//1
#include <iostream>
class Number {
private:
    int value;
public:
    Number(int v) : value(v) {}
    void setValue(int v) { value = v; }
    friend void printValue(const Number& n);
};
void printValue(const Number& n) { std::cout << "Value: " << n.value << std::endl; }

//2
class Value {
private:
    int val;
public:
    Value(int v) : val(v) {}
    friend int sum(const Value& v1, const Value& v2);
};
int sum(const Value& v1, const Value& v2) { return v1.val + v2.val; }

//3
class Data {
private:
    int d;
public:
    Data(int v) : d(v) {}
    friend Data max(const Data&, const Data&);
    void show() const { std::cout << d << std::endl; }
};
Data max(const Data& a, const Data& b) { return (a.d > b.d) ? a : b; }


//4
class Point {
private:
    int x, y;
public:
    Point(int a, int b) : x(a), y(b) {}
    friend bool areEqual(const Point&, const Point&);
};
bool areEqual(const Point& p1, const Point& p2) { return p1.x == p2.x && p1.y == p2.y; }


//5
class Multiplier {
private:
    int m;
public:
    Multiplier(int v) : m(v) {}
    friend int multiply(const Multiplier& a, const Multiplier& b);
};
int multiply(const Multiplier& a, const Multiplier& b) { return a.m * b.m; }


//6
class Number {
private:
    int num;
public:
    Number(int n) : num(n) {}
    friend int diff(const Number&, const Number&);
};
int diff(const Number& a, const Number& b) { return a.num - b.num; }


//7
class Container {
private:
    int val;
public:
    Container(int v) : val(v) {}
    void print() const { std::cout << val << std::endl; }
    friend void swap(Container&, Container&);
};
void swap(Container& a, Container& b) { int t = a.val; a.val = b.val; b.val = t; }


//8
class Value {
private:
    int num;
public:
    Value(int n) : num(n) {}
    friend int min(const Value&, const Value&, const Value&);
};
int min(const Value& a, const Value& b, const Value& c) {
    return std::min({a.num, b.num, c.num});
}


//9
class Employee {
private:
    double salary;
public:
    Employee(double s) : salary(s) {}
    friend Employee higherSalary(const Employee&, const Employee&);
    void show() const { std::cout << "Salary: " << salary << std::endl; }
};
Employee higherSalary(const Employee& e1, const Employee& e2) {
    return e1.salary > e2.salary ? e1 : e2;
}


//10
class Point {
private:
    int x, y;
public:
    Point(int a, int b) : x(a), y(b) {}
    friend int distance(const Point&, const Point&);
};
int distance(const Point& p1, const Point& p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}


//11
class Box {
private:
    int size;
public:
    Box(int s) : size(s) {}
    friend Box operator+(const Box&, const Box&);
    void print() const { std::cout << "Size: " << size << std::endl; }
};
Box operator+(const Box& a, const Box& b) { return Box(a.size + b.size); }


//12
class User {
private:
    int id;
public:
    User(int i) : id(i) {}
    friend bool operator==(const User& u1, const User& u2);
};
bool operator==(const User& u1, const User& u2) { return u1.id == u2.id; }


//13
#include <iostream>
class Product {
private:
    int price;
public:
    Product(int p) : price(p) {}
    friend std::ostream& operator<<(std::ostream& os, const Product& p);
};
std::ostream& operator<<(std::ostream& os, const Product& p) { os << "Product price: " << p.price; return os; }


//14
#include <iostream>
class Student {
private:
    std::string name;
public:
    Student() {}
    friend std::istream& operator>>(std::istream& is, Student& s);
    void show() const { std::cout << "Name: " << name << std::endl; }
};
std::istream& operator>>(std::istream& is, Student& s) { is >> s.name; return is; }


//15
class Score {
private:
    int sc;
public:
    Score(int s) : sc(s) {}
    friend Score max(const Score&, const Score&, const Score&);
    void show() const { std::cout << sc << std::endl; }
};
Score max(const Score& a, const Score& b, const Score& c) {
    return (a.sc > b.sc && a.sc > c.sc) ? a : (b.sc > c.sc ? b : c);
}


//16
class Admin;

class Database {
private:
    std::string data;
public:
    Database(std::string d) : data(d) {}
    friend class Admin;
};

class Admin {
public:
    void showData(const Database& db) { std::cout << "Data: " << db.data << std::endl; }
};


//17
class Logger;

class System {
private:
    std::string log;
public:
    System(std::string txt) : log(txt) {}
    friend class Logger;
};

class Logger {
public:
    void log(const System& sys) { std::cout << "Log: " << sys.log << std::endl; }
};


//18
class Student;
class Teacher {
public:
    void showStudent(const Student&);
};

class Student {
private:
    std::string name;
public:
    Student(std::string n) : name(n) {}
    friend class Teacher;
};

void Teacher::showStudent(const Student& st) { std::cout << "Student: " << st.name << std::endl; }


//19
class SecurityManager;

class SecureData {
private:
    int secret;
public:
    SecureData(int s) : secret(s) {}
    friend class SecurityManager;
};

class SecurityManager {
public:
    void access(const SecureData& sd) { std::cout << "Secret: " << sd.secret << std::endl; }
};

//20
class BankManager;

class Account {
private:
    double balance;
public:
    Account(double b) : balance(b) {}
    friend class BankManager;
};

class BankManager {
public:
    double viewBalance(const Account& acc) { return acc.balance; }
    void modifyBalance(Account& acc, double newBalance) { acc.balance = newBalance; }
};
