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
    std::wcout << L"числа в порядке от 1 до 20"<< std::endl;
    for(int i = 1 ; i<=20 ; i+= 2){
        std::wcout << i <<L" ,  ";
    }

   std::wcout<<std::endl;

    std::wcout << L"числа в порядке от 20 до 1"<< std::endl;
   for(int i = 20 ; i>=1 ; i-= 2){
        std::wcout << i <<L" ,  ";
    }

    std::wcout<<std::endl;

    return 0;
}

