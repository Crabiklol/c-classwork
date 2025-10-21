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
    std::wcout << L"Введите количество чисел: ";
    std::wcin >> n;

    if (n <= 0) {
        std::wcout << L"Количество чисел должно быть положительным" << std::endl;
        return 1;
    }
    int prev, current;
    std::wcout << L"Введите первое число: ";
    std::wcin >> prev;

    int i = 1;
    while (i < n) {
        std::wcout << L"Введите следующее число: ";
        std::wcin >> current;
        if (current < prev) {
            std::wcout << L"Число " << current << L" меньше предыдущего (" << prev << ")" << std::endl;
        }
        prev = current;
        i++;
    }
    return 0;
}
