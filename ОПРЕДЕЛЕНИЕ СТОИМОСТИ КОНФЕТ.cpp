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
    std::wcout << L"ОПРЕДЕЛЕНИЕ СТОИМОСТИ КОНФЕТ"<<std::endl<<std::endl;

    double price; // цена за 1 кг

    // Ввод цены
    std::wcout << L"Введите цену за 1 кг конфет, руб: ";
    std::wcin >> price;


    std::wcout << L"Результаты: "<<std::endl;
    int i = 1;
    while (i <= 10) {
        std::wcout << i << L" кг = " << i * price << L" руб."<<std::endl;
        i++;
    }
}
