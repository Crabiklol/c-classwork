//// 1.Типы данных и управляющие конструкции 
1)

Целочисленные 
int 4 байта
short 2 байта
long 4 или 8 байт
char 1 байт

Вещественные
float 4 байта
double 8 байт
long double 8 или 16 байт

Логический 
bool 1 байт true/false

2)

неявное преобразование 

явное преобразование 

3)

! инверсия 
&& и
|| или

!>&&>||

4)

if — простое ветвление 
if else - выбор между двумя вариантами
switch - множественное ветвление по целочисленному значению 


5)

enum задает набор именованных констант
    enum Color { RED, GREEN, BLUE };
    Color c = RED;

    switch (c) {
    case RED: /* код для красного */ break;
    case GREEN: /* код для зелёного */ break;
        // ...
    }





6)

Объявление(прототип) :

тип_возврата имя_функции(параметры);


Определение:

тип_возврата имя_функции(параметры) {
    // тело функции
    return значение;
}


пример

int sum(int a, int b); // объявление

int sum(int a, int b) { // определение
    return a + b;
}


7) Передача аргументов : по значению, по ссылке, по указателю

По значению :

void func(int x) { x = 10; } // изменение не затронет оригинал


По ссылке :

void func(int& x) { x = 10; } // изменит оригинал


По указателю :

void func(int* x) { *x = 10; } // изменит оригинал через разыменование




8). Одномерные массивы.Индексация.Передача массива в функцию

Объявление :

int arr[5] = { 1, 2, 3, 4, 5 };

Индексация: arr[0] — первый элемент, arr[4] — последний.

Передача в функцию :


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

9). Связь массивов и указателей.Арифметика указателей

Имя массива — это указатель на первый элемент :


int arr[3] = { 10, 20, 30 };
int* ptr = arr; // ptr указывает на arr[0]
Арифметика:

ptr + 1 — адрес следующего элемента;

*(ptr + 1) — значение следующего элемента.




10). Динамическая память : new, delete

Выделение памяти :


int* arr = new int[n]; // массив из n элементов
Освобождение:


delete[] arr; // для массивов
delete ptr;    // для одиночных объектов


11). Различие между const int* p и int* const p

const int* p — указатель на константное целое(нельзя менять значение через указатель) :

    
    const int* p = &x;
// *p = 10; // ошибка
int* const p — константный указатель(нельзя менять адрес) :

    
    int* const p = &x;
// p = &y; // ошибка










Практические задания 

#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, ("Russian"));

    int N;
    do {
        cout << "Введите размер массива (N >= 5): ";
        cin >> N;
    } while (N < 5);

    int* arr = new int[N]; // динамическое создание массива

    // заполнение 
    for (int i = 0; i < N; i++) {
        cout << "Введите элемент " << i + 1 << ": ";
        cin >> arr[i];
    }

    // вычисление суммы и поиска максимума
    int sum = 0, maxVal = arr[0];
    for (int i = 0; i < N; i++) {
        sum += arr[i];
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    cout << "Сумма элементов: " << sum << endl;
    cout << "Максимальный элемент: " << maxVal << endl;

    delete[] arr; // освобождение памяти
    return 0;
}






#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Обмен элементов
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, ("Russian"));

    
    const int SIZE = 10;
    int arr[SIZE];

    cout << "Введите 10 целых чисел:\n";
    for (int i = 0; i < SIZE; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr, SIZE);
    cout << "Отсортированный массив:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}













#include <iostream>
using namespace std;

// Перечисление операций
enum Operation { ADD, SUB, MUL, DIV };

// Функции для операций
double add(double a, double b) { return a + b; }
double sub(double a, double b) { return a - b; }
double mul(double a, double b) { return a * b; }
double div(double a, double b) {
    if (b == 0) {
        cout << "Ошибка: деление на ноль!\n";
        return 0;
    }
    return a / b;
}

int main() {
    setlocale(LC_ALL, ("Russian"));

    double num1, num2;
    int opChoice;

    cout << "Введите первое число: ";
    cin >> num1;
    cout << "Введите второе число: ";
    cin >> num2;

    cout << "Выберите операцию:\n";
    cout << "0 - Сложение (+)\n";
    cout << "1 - Вычитание (-)\n";
    cout << "2 - Умножение (*)\n";
    cout << "3 - Деление (/)\n";
    cout << "Ваш выбор: ";
    cin >> opChoice;

    // Указатель на функцию
    double (*operationPtr)(double, double);

    // Выбор функции в зависимости от выбора пользователя
    switch (opChoice) {
    case ADD:
        operationPtr = add;
        break;
    case SUB:
        operationPtr = sub;
        break;
    case MUL:
        operationPtr = mul;
        break;
    case DIV:
        operationPtr = div;
        break;
    default:
        cout << "Неверный выбор операции!\n";
        return 1;
    }

    // Вызов функции через указатель и вывод результат
    double result = operationPtr(num1, num2);
    cout << "Результат: " << result << endl;

    return 0;
}


