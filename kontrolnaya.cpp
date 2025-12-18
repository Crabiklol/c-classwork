//#1
#include <iostream> 

int main() {

    const int SIZE = 10;
    int numbers[SIZE];
    int sumPositive = 0;

    std::cout << "proga youuu" << std::endl;

    std::cout << "Please paste the  " << SIZE << " integer number:" << std::endl;
    for (int i = 0; i < SIZE; ++i) {
        std::cout << "element [" << i << "]: ";
        std::cin >> numbers[i];
    }

    std::cout << "\nmassive: ";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << numbers[i] << " ";

        
        if (numbers[i] > 0) {
            sumPositive += numbers[i];
        }
    }

    
    std::cout << "\n\n-----------------------------------------------" << std::endl;
    std::cout << "sum of the 10 element in massive: " << sumPositive << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;

    return 0;
}

//#2

#include <iostream>

long long calculateEvenIndexSum(const int arr[], int size) {
    long long sum = 0; 

   
    if (size <= 0) {
        return 0;
    }

   
    for (int i = 0; i < size; i += 2) {
        sum += arr[i];
    }

    return sum;
}

int main() {

    setlocale(LC_ALL, "Russian");

    const int ARRAY_SIZE = 10;
    int myNumbers[ARRAY_SIZE];

    std::cout << "--- Программа расчета суммы элементов на четных индексах ---" << std::endl;
    std::cout << "Введите " << ARRAY_SIZE << " целых чисел для заполнения массива:" << std::endl;

    
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << "Индекс [" << i << "]: ";
        while (!(std::cin >> myNumbers[i])) { 
            std::cout << "Ошибка ввода! Пожалуйста, введите целое число: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }

    long long totalSum = calculateEvenIndexSum(myNumbers, ARRAY_SIZE);

    std::cout << "\nСодержимое массива:" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (i % 2 == 0) {
            std::cout << "[" << myNumbers[i] << "] ";
        }
        else {
            std::cout << myNumbers[i] << " ";
        }
    }

    std::cout << "\n\nРезультат вычислений:" << std::endl;
    std::cout << "Сумма элементов на четных индексах (0, 2, 4, 6, 8): " << totalSum << std::endl;

    return 0;
}

//#3
#include <iostream> 


void replaceNegativesWithZeros(int arr[], int size) {

    if (size <= 0) return;


    for (int i = 0; i < size; ++i) {
     
        if (arr[i] < 0) {
            arr[i] = 0; 
        }
    }
}


void printArray(const int arr[], int size) {
    std::cout << "[ ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << (i == size - 1 ? "" : ", ");
    }
    std::cout << " ]" << std::endl;
}

int main() {
    
    setlocale(LC_ALL, "Russian");

    const int ARRAY_SIZE = 10;
    int numbers[ARRAY_SIZE];

    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        numbers[i] = rand() % 101 - 50;
    }

    std::cout << "--- Демонстрация модификации массива ---" << std::endl;

    std::cout << "\nИсходный массив (до вызова функции):" << std::endl;
    printArray(numbers, ARRAY_SIZE);

    replaceNegativesWithZeros(numbers, ARRAY_SIZE);


    std::cout << "\nМассив после замены отрицательных чисел нулями:" << std::endl;
    printArray(numbers, ARRAY_SIZE);

    std::cout << "\nПроверка завершена: все отрицательные значения успешно обнулены." << std::endl;

    return 0;
}

//#4
#include <iostream>
#include <limits>  

int findMinimum(const int arr[], int size);

int main() {
  
    setlocale(LC_ALL, "Russian");

    const int SIZE = 8;
    int data[SIZE];

    std::cout << "--- Программа поиска минимального значения в массиве ---" << std::endl;
    std::cout << "Введите " << SIZE << " целых чисел:" << std::endl;

  
    for (int i = 0; i < SIZE; ++i) {
        std::cout << "Элемент #" << i << ": ";
        while (!(std::cin >> data[i])) {
            std::cout << "Ошибка! Введите целое число: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    int minVal = findMinimum(data, SIZE);

    std::cout << "\n----------------------------------------" << std::endl;
    std::cout << "Минимальный элемент в массиве: " << minVal << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    return 0;
}


int findMinimum(const int arr[], int size) {
    if (size <= 0) return 0;

    int min = arr[0];

    for (int i = 1; i < size; ++i) {

        if (arr[i] < min) {
            min = arr[i]; 
        }
    }
    return min;
}
//#5
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int mas[10];
    int sum = 0;

    cout << "Введите 10 чисел:" << endl;

    for (int i = 0; i < 10; i++) {
        cin >> mas[i];
    }

   
    cout << "Ваш массив: ";
    for (int i = 0; i < 10; i++) {
        cout << mas[i] << " ";

        if (mas[i] > 0) {
            sum += mas[i]; 
        }
    }

    
    cout << endl << "Сумма положительных: " << sum << endl;

    return 0;
}

//#6
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    const int n = 10;
    int a[n] = { 15, 3, 8, 1, 10, 5, 20, 2, 7, 4 };
    int key;

   
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
              
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }


    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;


    cout << "Введите число, которое хотите найти: ";
    cin >> key;

    int position = -1; 
    for (int i = 0; i < n; i++) {
        if (a[i] == key) {
            position = i; 
            break;        
        }
    }

    
    if (position != -1) {
        cout << "Число найдено на позиции: " << position << endl;
    }
    else {
        cout << "Такого числа в массиве нет." << endl;
    }

    return 0;
}


//#7
#include <iostream>

int main() {
    setlocale(LC_ALL, "Russia");

    const int SIZE = 10;
    int arr[SIZE] = { 14, 2, 56, 31, 8, 90, 1, 45, 12, 7 };

    std::cout << "Исходный массив до сортировки" << std::endl;
    for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl << std::endl;

    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {

            if (arr[j] < arr[j + 1]) {
              
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    std::cout << " Массив после сортировки по убыванию " << std::endl;
    for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

//#8

#include <iostream>

using namespace std;

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j; 
            }
        }

        int temp = a[i];
        a[i] = a[min_idx];
        a[min_idx] = temp;
    }
}

int main() {
    int mas[10] = { 5, 2, 9, 1, 10, 6, 3, 8, 4, 7 };
    int size = 10;

    selectionSort(mas, size);

    
    cout << "Отсортированный массив: ";
    for (int i = 0; i < size; i++) {
        cout << mas[i] << " ";
    }

    return 0;
}

//#9

#include <iostream>

using namespace std;


void insertionSort(int arr[], int size) {
   
    for (int i = 1; i < size; i++) {
        int key = arr[i]; 
        int j = i - 1;    


        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; 
            j = j - 1;          
        }

      
        arr[j + 1] = key;
    }
}

int main() {
    
    setlocale(LC_ALL, "Russian");

    const int n = 10;
    int data[n] = { 34, 12, 5, 78, 1, 45, 23, 10, 8, 19 };

    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    
    insertionSort(data, n);

    cout << "Отсортированный массив (вставки): ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}


//#10

#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");


    const int ROWS = 5;
    const int COLS = 5;
    int matrix[ROWS][COLS];
    int mainDiagonalSum = 0;

    std::cout << "--- Работа с двумерным массивом 5x5 ---" << std::endl;

    std::cout << "Введите элементы матрицы (25 чисел):" << std::endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << "Элемент [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }

    std::cout << "\nВаша матрица:" << std::endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << matrix[i][j] << " ";

            
                mainDiagonalSum += matrix[i][j];
            }
        }
        std::cout << std::endl; 

    return 0;
}


//#11
#include <iostream>
#include <iomanip>
const int SIZE = 4;


void findMaxInRows(const int matrix[SIZE][SIZE]) {
    std::cout << "\nАнализ строк матрицы:" << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    
    for (int i = 0; i < SIZE; ++i) {

        
        int maxVal = matrix[i][0];

       
        for (int j = 1; j < SIZE; ++j) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j]; 
            }
        }

        
        std::cout << "Строка №" << i << ": максимальный элемент = " << maxVal << std::endl;
    }
    std::cout << "---------------------------------------" << std::endl;
}


void printMatrix(const int matrix[SIZE][SIZE]) {
    std::cout << "Исходная матрица 4x4:" << std::endl;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << std::setw(4) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    
    setlocale(LC_ALL, "Russian");

   
    int myData[SIZE][SIZE] = {
        {15, 42, 7, 23},
        {88, 12, 91, 5},
        {30, 10, 2, 54},
        {19, 77, 44, 33}
    };

    
    printMatrix(myData);

   
    findMaxInRows(myData);

    return 0;
}


//#12

#include <iostream>


void incrementCounter() {

    static int counter = 0;

    
    counter++;


    std::cout << "Функция вызвана. Текущее значение счётчика: " << counter << std::endl;
}

int main() {
    
    setlocale(LC_ALL, "Russian");

    std::cout << "--- Демонстрация работы статического счётчика ---" << std::endl;

    incrementCounter();
    incrementCounter(); 
    incrementCounter(); 

    std::cout << "\nВыполняем цикл для имитации нагрузки:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        incrementCounter(); 
    }

    std::cout << "-------------------------------------------------" << std::endl;

    return 0;
}


//#14

#include <iostream>

using namespace std;


auto getAverage(int arr[], int size) -> double {
    double sum = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i]; 
    }

    return sum / size; 
}

int main() {

    int mas[5] = { 1, 2, 3, 4, 6 };

    double result = getAverage(mas, 5);

    cout << "Среднее арифметическое: " << result << endl;

    return 0;
}


//#15

#include <iostream>

using namespace std;


void printLine(char sym = '#', int count = 5) {
    for (int i = 0; i < count; i++) {
        cout << sym;
    }
    cout << endl; 
}

int main() {
   
    printLine();

 
    printLine('@');


    printLine('!', 12);

    return 0;
}

//#16

#include <iostream>

inline int getMax(int a, int b) {

    return (a > b) ? a : b;
}

int main() {

    setlocale(LC_ALL, "Russian");

    int x = 42;
    int y = 73;

    std::cout << "--- Демонстрация работы inline-функции ---" << std::endl;
    std::cout << "Число X: " << x << std::endl;
    std::cout << "Число Y: " << y << std::endl;


    int maximum = getMax(x, y);

    std::cout << "\nРезультат вычисления максимума: " << maximum << std::endl;
    std::cout << "------------------------------------------" << std::endl;

 
    std::cout << "Максимум из 100 и 500: " << getMax(100, 500) << std::endl;

    return 0;
}


//#17

#include <iostream>

using namespace std;

void print(int n) {
    cout << "Это целое число: " << n << endl;
}

void print(double d) {
    cout << "Это дробное число: " << d << endl;
}

void print(int arr[], int size) {
    cout << "Это массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int a = 10;
    double b = 5.5;
    int mas[3] = { 1, 2, 3 };

    print(a);          
    print(b);          
    print(mas, 3);     

    return 0;
}


//#18

#include <iostream>

using namespace std;

int main() {

    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for (int i = 0; i < 3; i++) {
        for (int j = i; j < 3; j++) {
            
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }

   
    cout << "Транспонированная матрица:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl; 
    }

    return 0;
}

//#19


#include <iostream>

using namespace std;


int sum(int a = 0, int b = 0) {
    return a + b;
}


int sum(int arr[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i]; 
    }
    return total;
}

int main() {
    
    cout << "Сумма 5 и 10: " << sum(5, 10) << endl;
    cout << "Сумма только 7 (второе число 0): " << sum(7) << endl;
    cout << "Вызов без чисел (0+0): " << sum() << endl;

    
    int mas[4] = { 1, 2, 3, 4 };
    cout << "Сумма массива: " << sum(mas, 4) << endl;

    return 0;
}

//#20

#include <iostream>

using namespace std;

int main() {
   
    setlocale(LC_ALL, "Russia");
    int n = 15;
    int a[15] = { 23, 5, 1, 88, 12, 7, 45, 3, 90, 10, 6, 2, 67, 14, 30 };
    int target;

    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            
            if (a[j] < a[i]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    cout << "Отсортированный список: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "\nКакое число вы хотите найти? ";
    cin >> target;

    int position = -1; 


    for (int i = 0; i < n; i++) {
        if (a[i] == target) {
            position = i; 
            break;       
        }
    }

    if (position != -1) {
        cout << "Успех! Число найдено на позиции: " << position << endl;
    }
    else {
        cout << "К сожалению, такого числа в списке нет." << endl;
    }

    return 0;
}



