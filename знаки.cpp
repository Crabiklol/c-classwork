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
    wchar_t ch;

    std::wcout << L"Введите символ: ";
    std::wcin >> ch;

    if (ch >= '0' && ch <= '9') {
        std::wcout << L"это цифра" << std::endl;
    } else {
        switch (ch) {
        case 'A': case 'E': case 'I': case 'O': case 'U': case 'Y':
            std::wcout << L"это буква латинская заглавная гласная" << std::endl;
            break;
        case 'a': case 'e': case 'i': case 'o': case 'u': case 'y':
            std::wcout << L"это буква латинская строчная гласная" << std::endl;
            break;
        case 'B': case 'C': case 'D': case 'F': case 'G': case 'H':
        case 'J': case 'K': case 'L': case 'M': case 'N': case 'P':
        case 'Q': case 'R': case 'S': case 'T': case 'V': case 'W':
        case 'X': case 'Z':
            std::wcout << L"это буква латинская заглавная согласная" << std::endl;
            break;
        case 'b': case 'c': case 'd': case 'f': case 'g': case 'h':
        case 'j': case 'k': case 'l': case 'm': case 'n': case 'p':
        case 'q': case 'r': case 's': case 't': case 'v': case 'w':
        case 'x': case 'z':
            std::wcout << L"это буква латинская строчная согласная" << std::endl;
            break;
        case L'А': case L'Е': case L'Ё': case L'И': case L'О':
        case L'У': case L'Ы': case L'Э': case L'Ю': case L'Я':
            std::wcout << L"это буква русская заглавная гласная" << std::endl;
            break;
        case L'а': case L'е': case L'ё': case L'и': case L'о':
        case L'у': case L'ы': case L'э': case L'ю': case L'я':
            std::wcout << L"это буква русская строчная гласная" << std::endl;
            break;
        case L'Б': case L'В': case L'Г': case L'Д': case L'Ж': case L'З':
        case L'К': case L'Л': case L'М': case L'Н': case L'П': case L'Р':
        case L'С': case L'Т': case L'Ф': case L'Х': case L'Ц': case L'Ч':
        case L'Ш': case L'Щ':
            std::wcout << L"это буква русская заглавная согласная" << std::endl;
            break;
        case L'б': case L'в': case L'г': case L'д': case L'ж': case L'з':
        case L'к': case L'л': case L'м': case L'н': case L'п': case L'р':
        case L'с': case L'т': case L'ф': case L'х': case L'ц': case L'ч':
        case L'ш': case L'щ':
            std::wcout << L"это буква русская строчная согласная" << std::endl;
            break;
        default:
            std::wcout << L"это не буква и не цифра" << std::endl;
            break;
        }
    }
    return 0;
}





