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
    std::wcout<<L"ПОВТОРЯЮЩЕЕ ЧИСЛО"<<std::endl<<std::endl;
    int number;
    unsigned int numberRepeatCount;
    std::wcout<<L"Введите целое число: ";
    std::wcin>>number;
    std::wcout<< L"Введите количество раз , которое его нужно повторить: ";
    std::wcin>>numberRepeatCount;
    std::wcout<<std::endl;
    std::wcout<<L"Последовательность из повторяющего числа: "<<std::endl;
    for(unsigned short i = 0; i< numberRepeatCount; ++i){
             std::wcout<<number<<L", ";
    }
    if (numberRepeatCount > 0){
        std::wcout<<number;
    }
    else {
        std::wcout<<L"Последовательность не содержит чисел. ";
    }
    std::wcout<<std::endl<<std::endl;
    return 0;
}
