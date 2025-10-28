#include <iostream>
#ifdef _WIN32
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <io.h>
#include <fcntl.h>
#endif
int main(){
#ifdef _WIN32
    setlocale(LC_ALL, "");
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
#else
    std::ios_base::sync_with_stdio(false):
        std::wcout.imbue(std::locale("en_US.UTF-8"));
    std::wcin.imbue(std::locale("en_US.Utf-8"));
#endif
    int number;

    // Ввод числа
    std::wcout << L"Введите целое неотрицательное число: ";
    std::wcin >> number;

    // Проверка на корректность ввода
    if (number < 0) {
        std::wcout << L"Ошибка: число должно быть неотрицательным!" << std::endl;
        return 1;
    }

    int sum = 0;

    // Поиск делителей и их суммирование
    for(int i = 1; i < number; i++) {
        if(number % i == 0) {
            sum += i;
        }
    }
    std::wcout << L"Сумма всех делителей (кроме самого числа): " << sum << std::endl;

return 0;
}
