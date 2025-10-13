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
    int day_num;
    std::wcout<<L"ВЕДИТЕ НОМЕР НЕДЕЛИ: ";
    std::wcin >> day_num;
    switch(day_num){
    case 1:
        std::wcout <<L"Понедельник" << std::endl;
        break;
    case 2:
        std::wcout <<L"Вторник" << std::endl;
        break;
    case 3:
        std::wcout <<L"Среда" << std::endl;
        break;
    case 4:
        std::wcout <<L"Четверг" << std::endl;
        break;
    case 5:
        std::wcout <<L"Пятница" << std::endl;
        break;
    case 6:
        std::wcout <<L"суббота" << std::endl;
        break;
    case 7:
        std::wcout <<L"Воскресенье" << std::endl;
        break;
    }
    return 0;
}
