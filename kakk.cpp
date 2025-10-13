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
    enum Unit {
        MM = 0,    // миллиметр
        CM = 1,    // сантиметр
        DM = 2,    // дециметр
        M = 3,     // метр
        KM = 4     // километр
    };
    int unitNumber;
    double length;
    std::wcout << L"Соответствие чисел единицам измерения:" << std::endl;
    std::wcout << L"0 - миллиметр" << std::endl;
    std::wcout << L"1 - сантиметр" <<std::endl;
    std::wcout << L"2 - дециметр" << std::endl;
    std::wcout << L"3 - метр" << std::endl;
    std::wcout << L"4 - километр" << std::endl;

    std::wcout << L"Введите номер единицы измерения: ";
    std::wcin >> unitNumber;
    std::wcout << L"Введите длину отрезка: ";
    std::wcin >> length;

    Unit unit = static_cast<Unit>(unitNumber);

    double meters = 0.0;

    switch(unit) {
    case MM:
        meters = length * 0.001;
        break;
    case CM:
        meters = length * 0.01;
        break;
    case DM:
        meters = length * 0.1;
        break;
    case M:
        meters = length;
        break;
    case KM:
        meters = length * 1000;
        break;
    default:
        std::wcout << L"Ошибка: неверный номер единицы измерения" << std::endl;
        return 1;
    }

    std::wcout << L"Длина отрезка в метрах: " << meters << std::endl;

    return 0;
}
