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
    wchar_t symbol;
    int count;


    std::wcout << L"Введите символ: ";
    std::wcin >> symbol;


    std::wcout << L"Введите количество строк: ";
    std::wcin >> count;


    if (count < 0) {
        std::wcout << L"Количество должно быть неотрицательным!" << std::endl;
        return 1;
    }


    int currentLine = 1;

    while (currentLine <= count) {

        int currentSymbol = 1;


        while (currentSymbol <= currentLine) {
            std::wcout << symbol;
            currentSymbol++;
        }


        std::wcout << std::endl;
        currentLine++;
    }

    return 0;
}
