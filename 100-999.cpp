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
        int number;

        std::wcout << L"Введите число в диапазоне 100-999: ";
        std::wcin >> number;

        if (number < 100 || number > 999) {
            std::wcout << L"Ошибка: число должно быть в диапазоне 100-999!" << std::endl;
            return 1;
        }

        int hundreds = number / 100;
        int tens = (number / 10) % 10;
        int units = number % 10;

        std::cout << number << " - ";

        switch (hundreds) {
        case 1: std::wcout << L"сто "; break;
        case 2: std::wcout << L"двести "; break;
        case 3: std::wcout << L"триста "; break;
        case 4: std::wcout << L"четыреста "; break;
        case 5: std::wcout << L"пятьсот "; break;
        case 6: std::wcout << L"шестьсот "; break;
        case 7: std::wcout << L"семьсот "; break;
        case 8: std::wcout << L"восемьсот "; break;
        case 9: std::wcout << L"девятьсот "; break;
        }

        if (tens == 1) {
            std::cout << " ";
            switch (units) {
            case 0: std::wcout << L"десять "; break;
            case 1: std::wcout << L"одиннадцать "; break;
            case 2: std::wcout << L"двенадцать "; break;
            case 3: std::wcout << L"тринадцать "; break;
            case 4: std::wcout << L"четырнадцать "; break;
            case 5: std::wcout << L"пятнадцать "; break;
            case 6: std::wcout << L"шестнадцать "; break;
            case 7: std::wcout << L"семнадцать "; break;
            case 8: std::wcout << L"восемнадцать "; break;
            case 9: std::wcout << L"девятнадцать "; break;
            }
        } else {
            if (tens > 0) {
                std::cout << " ";
                switch (tens) {
                case 2: std::wcout << L"двадцать "; break;
                case 3: std::wcout << L"тридцать "; break;
                case 4: std::wcout << L"сорок "; break;
                case 5: std::wcout << L"пятьдесят "; break;
                case 6: std::wcout << L"шестьдесят "; break;
                case 7: std::wcout << L"семьдесят "; break;
                case 8: std::wcout << L"восемьдесят "; break;
                case 9: std::wcout << L"девяносто "; break;
                }
            }

            if (units > 0) {
                std::cout << " ";
                switch (units) {
                case 1: std::wcout << L"один "; break;
                case 2: std::wcout << L"два "; break;
                case 3: std::wcout << L"три "; break;
                case 4: std::wcout << L"четыре "; break;
                case 5: std::wcout << L"пять "; break;
                case 6: std::wcout << L"шесть "; break;
                case 7: std::wcout << L"семь "; break;
                case 8: std::wcout << L"восемь "; break;
                case 9: std::wcout << L"девять "; break;
                }
            }
        }

        std::wcout << std::endl;

        return 0;
    }




