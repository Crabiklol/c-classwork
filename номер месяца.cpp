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
        int mounth_num;
        std::wcout<<L"ВЕДИТЕ НОМЕР месяца: ";
        std::wcin >> mounth_num;
        switch(mounth_num){
        case 1:
        case 2:
        case 12:
            std::wcout <<L"зима" << std::endl;
            break;
        case 3:
        case 4:
        case 5:
            std::wcout <<L"весна" << std::endl;
            break;
        case 6:
        case 7:
        case 8:
            std::wcout <<L"лето" << std::endl;
            break;
        case 9:
        case 10:
        case 11:
            std::wcout <<L"осень" << std::endl;
            break;
        }
        return 0;
    }
