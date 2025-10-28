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
    int n;

    // Ввод числа
    std::wcout << L"Введите натуральное число: ";
    std::wcin >> n;

    int count = 0; // Счетчик подходящих чисел

    // Перебираем все числа от 1 до n
    for(int i = 1; i <= n; i++) {
        // Проверяем, что число не делится на 2, 3 и 5
        if(i % 2 != 0 && i % 3 != 0 && i % 5 != 0) {
            count++;
        }
    }

    // Выводим результат
    std::wcout << L"Количество чисел, не делящихся на 2, 3 и 5: " << count << std::endl;

    return 0;
}
