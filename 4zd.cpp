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
    std::wcout<<L"Программа для подсчета сммы 5 целых чисел"<<std::endl;
    int sum=0;
    for(int i=1; i<=5; i++){
        int num = 0 ;
        std::wcout<<L"Число "<<i<<L" : ";
        std::wcin>>num;
        sum+=num;
    }
    std::wcout<<L"Сумма: "<<sum<<std::endl;
    return 0;
}
