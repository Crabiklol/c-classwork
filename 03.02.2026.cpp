//1
#include <iostream>
using namespace std;


int sum(int a, int b) {
    return a + b;
}


int sum(int a, int b, int c) {
    return a + b + c;
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    cout << "Сумма двух чисел (5 + 7): " << sum(5, 7) << endl;

   
    cout << "Сумма трёх чисел (3 + 4 + 8): " << sum(3, 4, 8) << endl;

    return 0;
}

//2
#include <iostream>
using namespace std;


void print(int num) {
    cout << "Целое число: " << num << endl;
}


void print(double num) {
    cout << "Вещественное число: " << num << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    print(42);           
    print(3.14159); 

    return 0;
}

//3
#include <iostream>
using namespace std;


int maxValue(int a, int b) {
    return (a > b) ? a : b;
}


double maxValue(double a, double b) {
    return (a > b) ? a : b;
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Максимум из 10 и 25: " << maxValue(10, 25) << endl;
    cout << "Максимум из 3.14 и 2.71: " << maxValue(3.14, 2.71) << endl;

    return 0;
}

//4
#include <iostream>
using namespace std;


int square(int num) {
    return num * num;
}


double square(double num) {
    return num * num;
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Квадрат числа 7: " << square(7) << endl;
    cout << "Квадрат числа 3.5: " << square(3.5) << endl;


    return 0;
}
//5
#include <iostream>
using namespace std;


int absValue(int x) {
    return (x >= 0) ? x : -x;
}


double absValue(double x) {
    return (x >= 0) ? x : -x;
}

int main() {
 
    cout << "|7| = " << absValue(7) << endl;
    cout << "|-7| = " << absValue(-7) << endl;
    cout << "|3.14| = " << absValue(3.14) << endl;
    cout << "|-2.5| = " << absValue(-2.5) << endl;

    return 0;
}

//6
#include <iostream>
using namespace std;


double average(int a, int b) {
    return static_cast<double>(a + b) / 2.0;
}


double average(int a, int b, int c) {
    return static_cast<double>(a + b + c) / 3.0;
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Среднее (10, 20): " << average(10, 20) << endl;
    cout << "Среднее (5, 15, 25): " << average(5, 15, 25) << endl;
    cout << "Среднее (1, 2): " << average(1, 2) << endl;
    cout << "Среднее (3, 6, 9): " << average(3, 6, 9) << endl;

    return 0;
}

//7
#include <iostream>
using namespace std;


void printArray(const int arr[], int size) {
    cout << "Одномерный массив: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void printArray(const int arr[][10], int rows, int cols) {
    cout << "Двумерный массив:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int arr1[] = { 1, 2, 3, 4, 5 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    printArray(arr1, size1);


    int arr2[3][10] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int rows = 3;
    int cols = 3;
    printArray(arr2, rows, cols);

    return 0;
}

//8
#include <iostream>
#include <climits>  
using namespace std;


int minValue(int a, int b) {
    return (a < b) ? a : b;
}


int minValue(const int arr[], int size) {
    if (size <= 0) {
        cerr << "Ошибка: размер массива <= 0!" << endl;
        return 0; 
    }

    int minVal = arr[0]; 
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Минимум из 10 и 5: " << minValue(10, 5) << endl;

  
    int arr[] = { 7, 3, 9, 1, 4 };
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Минимальный элемент массива: " << minValue(arr, size) << endl;

  
    int single[] = { 42 };
    cout << "Минимальный элемент одиночного массива: " << minValue(single, 1) << endl;

    return 0;
}
//9
#include <iostream>
using namespace std;


void swapValues(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapValues(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int x = 10, y = 20;
    cout << "До обмена (int): x = " << x << ", y = " << y << endl;
    swapValues(x, y);
    cout << "После обмена (int): x = " << x << ", y = " << y << endl;

    
    double p = 3.14, q = 2.71;
    cout << "До обмена (double): p = " << p << ", q = " << q << endl;
    swapValues(p, q);
    cout << "После обмена (double): p = " << p << ", q = " << q << endl;

    return 0;
}

//10

#include <iostream>
using namespace std;


double power(double base) {
    return base * base;
}

double power(double base, int exponent) {
    if (exponent == 0) {
        return 1.0; 
    }

    double result = 1.0;
    int absExponent = (exponent < 0) ? -exponent : exponent; 


    for (int i = 0; i < absExponent; ++i) {
        result *= base;
    }

    
    if (exponent < 0) {
        result = 1.0 / result;
    }

    return result;
}

int main() {
    setlocale(LC_ALL, "Russian");
    double x = 5.0;
    cout << x << " в квадрате = " << power(x) << endl;

    double y = 2.0;
    int n = 4;
    cout << y << " в степени " << n << " = " << power(y, n) << endl;

    double z = 3.0;
    int m = -2;
    cout << z << " в степени " << m << " = " << power(z, m) << endl;

    double w = 7.0;
    int p = 0;
    cout << w << " в степени " << p << " = " << power(w, p) << endl;

    return 0;
}

//11
#include <iostream>
using namespace std;


int sumArray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

double sumArray(double arr[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}


int main() {
    setlocale(LC_ALL, "Russian");
    int intArr[] = { 1, 2, 3, 4, 5 };
    int intSize = 5;

   
    double doubleArr[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    int doubleSize = 5;

    
    cout << "Сумма int-массива: " << sumArray(intArr, intSize) << endl;
    cout << "Сумма double-массива: " << sumArray(doubleArr, doubleSize) << endl;

    return 0;
}

//12

#include <iostream>
#include <climits>  
using namespace std;


int findMax(int arr[10]) {
    int maxVal = arr[0];  
    for (int i = 1; i < 10; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}


int findMax(int arr[], int size) {
    if (size <= 0) {
        throw invalid_argument("Размер массива должен быть > 0");
    }

    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}


int main() {
    
    int arr10[] = { 3, 7, 1, 9, 4, 8, 2, 6, 5, 0 };

 
    int arrN[] = { 15, 3, 22, 8, 11, 5, 19 };
    int sizeN = 7;

   
    cout << "Максимум в массиве из 10 элементов: " << findMax(arr1 Newton) << endl;
    cout << "Максимум в массиве из " << sizeN << " элементов: "
        << findMax(arrN, sizeN) << endl;

    return 0;
}
//13
#include <iostream>
using namespace std;


int countPositive(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            count++;
        }
    }
    return count;
}


int countPositive(int arr[][100], int rows, int cols) {
    
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > 0) {
                count++;
            }
        }
    }
    return count;
}


int main() {
    setlocale(LC_ALL, "Russian");
    int arr1D[] = { -3, 5, 0, 8, -1, 4 };
    int size1D = 6;

    
    int arr2D[3][100] = {
        {-2,  7, -1,  3},
        { 0, -4,  6, -8},
        { 5, -9,  2,  1}
    };
    int rows = 3, cols = 4;

   
    cout << "Положительных в одномерном массиве: "
        << countPositive(arr1D, size1D) << endl;

    cout << "Положительных в двумерном массиве: "
        << countPositive(arr2D, rows, cols) << endl;

    return 0;
}

//14
#include <iostream>
#include <iomanip>  
using namespace std;


void print(const int arr[], int size) {
    cout << "Целочисленный массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) {
            cout << " ";  
        }
    }
    cout << endl;
}


void print(const double arr[], int size) {
    cout << "Вещественный массив: ";
    cout << fixed << setprecision(2); 
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) {
            cout << " ";
        }
    }
    cout << endl;
    cout.unsetf(ios::fixed);  
}


int main() {
    setlocale(LC_ALL, "Russian");
    int intArr[] = { 1, -5, 10, 0, 7 };
    int intSize = 5;

   
    double doubleArr[] = { 3.14, -2.5, 0.0, 7.891, -1.234 };
    int doubleSize = 5;

    
    print(intArr, intSize);
    print(doubleArr, doubleSize);

    return 0;
}

//15
