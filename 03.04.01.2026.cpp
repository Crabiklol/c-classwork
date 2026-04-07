//1
#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;

public:
    Book(const std::string& t, const std::string& a) {
        setTitle(t);
        setAuthor(a);
    }

    void setTitle(const std::string& t) {
        if (!t.empty())
            title = t;
        else
            std::cerr << "Ошибка: название не может быть пустым.\n";
    }

    void setAuthor(const std::string& a) {
        if (!a.empty())
            author = a;
        else
            std::cerr << "Ошибка: автор не может быть пустым.\n";
    }

    std::string getTitle() const {
        return title;
    }

    std::string getAuthor() const {
        return author;
    }

    void printInfo() const {
        std::cout << "Книга: " << title << ", автор: " << author << std::endl;
    }
};
//2
class Counter {
private:
    int value;

public:
    Counter() : value(0) {}

    void setValue(int v) {
        if (v >= 0 && v <= 100)
            value = v;
        else
            std::cerr << "Ошибка: значение должно быть в диапазоне 0-100.\n";
    }

    void increment() {
        if (value < 100)
            value++;
    }

    void decrement() {
        if (value > 0)
            value--;
    }

    int getValue() const {
        return value;
    }
};
//3
class Player {
private:
    int hp;
    int level;

public:
    Player() : hp(100), level(1) {}

    void takeDamage(int damage) {
        if (damage < 0) return;
        hp -= damage;
        if (hp < 0) hp = 0;
    }

    void heal(int amount) {
        if (amount < 0) return;
        hp += amount;
        if (hp > 100) hp = 100;
    }

    void levelUp() {
        level++;
    }

    void showStats() const {
        std::cout << "HP: " << hp << ", Уровень: " << level << std::endl;
    }
};
//4
#include <string>

class Car {
private:
    std::string brand;
    double speed;

public:
    Car(const std::string& b) : brand(b), speed(0) {}

    void accelerate(double delta) {
        if (delta < 0) return;
        speed += delta;
    }

    void brake(double delta) {
        if (delta < 0) return;
        speed -= delta;
        if (speed < 0) speed = 0;
    }

    void showStatus() const {
        std::cout << "Машина: " << brand << ", Скорость: " << speed << " км/ч" << std::endl;
    }
};
//5
#include <iostream>

class WaterMeter {
private:
    int liters;

public:
    WaterMeter() : liters(0) {}

    void addLiters(int amount) {
        if (amount < 0) return;
        liters += amount;
    }

    void removeLiters(int amount) {
        if (amount < 0) return;
        if (amount > liters) {
            std::cerr << "Нельзя удалить больше, чем есть на счету.\n";
            return;
        }
        liters -= amount;
    }

    void showLiters() const {
        std::cout << "Показания счетчика воды: " << liters << " литров." << std::endl;
    }
};
//6
#include <vector>

class Book; // Предварительное объявление, если нужен отдельный файл

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void removeBook(const std::string& title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getTitle() == title) {
                books.erase(it);
                break;
            }
        }
    }

    void showBooks() const {
        for (const auto& book : books) {
            book.printInfo();
        }
    }
};
