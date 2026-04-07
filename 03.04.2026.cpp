//1
#include <iostream>
#include <string>
#include <vector>

class Author {
public:
    std::string name;
    Author(const std::string& n) : name(n) {}
};

class Book {
public:
    std::string title;
    Author* author;  // агрегация

    Book(const std::string& t, Author* a) : title(t), author(a) {}

    void show() {
        std::cout << "Книга: " << title << ", Автор: " << author->name << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Author author1("Лев Толстой");
    Book book1("Война и мир", &author1);

    book1.show();

    return 0;
}


//2
#include <iostream>
#include <vector>
#include <string>

class Furniture {
public:
    std::string name;
    Furniture(const std::string& n) : name(n) {}
};

class Room {
public:
    std::vector<Furniture> furniture_items;

    void addFurniture(const Furniture& f) {
        furniture_items.push_back(f);
    }

    void show() {
        std::cout << "Комната содержит:" << std::endl;
        for (const auto& item : furniture_items) {
            std::cout << "- " << item.name << std::endl;
        }
    }
};

int main() {
  setlocale(LC_ALL, "Russian");
    Room livingRoom;
    livingRoom.addFurniture(Furniture("Диван"));
    livingRoom.addFurniture(Furniture("Стол"));
    livingRoom.addFurniture(Furniture("Лампа"));

    livingRoom.show();

    return 0;
}
//3
#include <iostream>
#include <string>

class Account {
public:
    std::string login;
    std::string password;

    Account(const std::string& l, const std::string& p) : login(l), password(p) {}

    void show() {
        std::cout << "Логин: " << login << std::endl;
    }
};

class User {
public:
    std::string name;
    Account* account;  // композиция

    User(const std::string& n, const std::string& login, const std::string& pass)
        : name(n), account(new Account(login, pass)) {}

    ~User() {
        delete account;
    }

    void show() {
        std::cout << "Пользователь: " << name << std::endl;
        account->show();
    }
};

int main() {
   setlocale(LC_ALL, "Russian");
    User user1("Иван", "ivan123", "pass123");
    user1.show();

    return 0;
}
//4
#include <iostream>
#include <vector>
#include <string>

class Teacher {
public:
    std::string name;
    Teacher(const std::string& n) : name(n) {}
    void show() const {
        std::cout << "Учитель: " << name << std::endl;
    }
};

class School {
public:
    std::vector<Teacher*> teachers;

    void addTeacher(Teacher* t) {
        teachers.push_back(t);
    }

    void show() const {
        std::cout << "Учителя школы:" << std::endl;
        for (auto t : teachers) {
            t->show();
        }
    }
};

int main() {
   setlocale(LC_ALL, "Russian");
    Teacher t1("Петров Петр");
    Teacher t2("Иванов Иван");

    School school;
    school.addTeacher(&t1);
    school.addTeacher(&t2);

    school.show();

    return 0;
}
//5
#include <iostream>
#include <string>

class Wheel {
public:
    int number;
    Wheel(int n) : number(n) {}

    void show() const {
        std::cout << "Колесо №" << number << std::endl;
    }
};

class Car {
public:
    Wheel* wheels[4];

    Car() {
        for (int i = 0; i < 4; ++i) {
            wheels[i] = new Wheel(i + 1);
        }
    }

    ~Car() {
        for (int i = 0; i < 4; ++i) {
            delete wheels[i];
        }
    }

    void show() {
        std::cout << "Машина оснащена следующими колёсами:" << std::endl;
        for (int i = 0; i < 4; ++i) {
            wheels[i]->show();
        }
    }
};

int main() {
   setlocale(LC_ALL, "Russian");
    Car myCar;
    myCar.show();
    return 0;
}
//6
#include <iostream>
#include <vector>
#include <string>

class Employee {
public:
    std::string name;
    Employee(const std::string& n) : name(n) {}
    void show() const {
        std::cout << "Сотрудник: " << name << std::endl;
    }
};

class Company {
public:
    std::vector<Employee*> employees;

    void addEmployee(Employee* e) {
        employees.push_back(e);
    }

    void show() const {
        std::cout << "Сотрудники компании:" << std::endl;
        for (auto e : employees) {
            e->show();
        }
    }
};

int main() {
  setlocale(LC_ALL, "Russian");
    Employee e1("Алексей");
    Employee e2("Мария");

    Company comp;
    comp.addEmployee(&e1);
    comp.addEmployee(&e2);

    comp.show();
    return 0;
}
//7
#include <iostream>
#include <string>

class Keyboard {
public:
    void type() {
        std::cout << "Печать на клавиатуре..." << std::endl;
    }
};

class Laptop {
public:
    Keyboard* keyboard;

    Laptop() {
        keyboard = new Keyboard(); // композиция
    }

    ~Laptop() {
        delete keyboard;
    }

    void run() {
        std::cout << "Запуск ноутбука..." << std::endl;
        keyboard->type();
    }
};

int main() {
   setlocale(LC_ALL, "Russian");
    Laptop myLaptop;
    myLaptop.run();
    return 0;
}
//8
#include <iostream>
#include <vector>
#include <string>

class Student {
public:
    std::string name;
    Student(const std::string& n) : name(n) {}
    void show() const {
        std::cout << "Студент: " << name << std::endl;
    }
};

class Course {
public:
    std::vector<Student*> students;

    void addStudent(Student* s) {
        students.push_back(s);
    }

    void show() const {
        std::cout << "Студенты на курсе:" << std::endl;
        for (auto s : students) {
            s->show();
        }
    }
};

int main() {
   setlocale(LC_ALL, "Russian");
    Student s1("Анна");
    Student s2("Дмитрий");

    Course course;
    course.addStudent(&s1);
    course.addStudent(&s2);

    course.show();

    return 0;
}
//9
#include <iostream>
#include <vector>
#include <string>

class Door {
public:
    std::string material;
    Door(const std::string& m) : material(m) {}
    void show() const {
        std::cout << "Дверь из " << material << std::endl;
    }
};

class House {
public:
    std::vector<Door> doors;

    void addDoor(const Door& d) {
        doors.push_back(d);
    }

    void showDoors() const {
        std::cout << "Двери дома:" << std::endl;
        for (const auto& door : doors) {
            door.show();
        }
    }
};

int main() {
   setlocale(LC_ALL, "Russian");
    House myHouse;
    myHouse.addDoor(Door("дерево"));
    myHouse.addDoor(Door("металл"));

    myHouse.showDoors();

    return 0;
}
//10
#include <iostream>
#include <vector>
#include <string>

class Track {
public:
    std::string title;
    Track(const std::string& t) : title(t) {}
    void show() const {
        std::cout << "Трек: " << title << std::endl;
    }
};

class Player {
public:
    std::vector<Track*> tracks;

    void addTrack(Track* t) {
        tracks.push_back(t);
    }

    void showTracks() const {
        std::cout << "Плейлист:" << std::endl;
        for (auto t : tracks) {
            t->show();
        }
    }
};

int main() {
   setlocale(LC_ALL, "Russian");
    Track song1("Imagine");
    Track song2("Yesterday");

    Player player;
    player.addTrack(&song1);
    player.addTrack(&song2);

    player.showTracks();

    return 0;
}
