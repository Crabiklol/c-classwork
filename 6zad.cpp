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
    int a, b;


    std::wcout << L"Введите два целых числа: ";
    std::wcin >> a >> b;


    int start = (a < b) ? a : b;
    int end = (a < b) ? b : a;


    std::wcout << L"Вывод:\n";
    int i = start;
    while (i <= end) {
        std::wcout << i << L" ";
        i += 2;
    }
    std::wcout << std::endl;
    return 0;
}
