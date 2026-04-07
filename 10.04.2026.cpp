//1
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Через итератор
    std::cout << "Через итератор: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    // Через range-based for
    std::cout << "Через range-based for: ";
    for (int n : vec) {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    return 0;
}
//2
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 3, 5, 7, 9};
    int target = 5;

    auto it = std::find(vec.begin(), vec.end(), target);
    if (it != vec.end()) {
        std::cout << "Найдено\n";
    } else {
        std::cout << "Не найдено\n";
    }
    return 0;
}
//3
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {10, 4, 7, 2, 15};

    auto min_it = std::min_element(vec.begin(), vec.end());
    auto max_it = std::max_element(vec.begin(), vec.end());

    if (min_it != vec.end()) {
        std::cout << "Минимум: " << *min_it << '\n';
    }
    if (max_it != vec.end()) {
        std::cout << "Максимум: " << *max_it << '\n';
    }

    return 0;
}
//4
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 2, 4, 2, 5};
    int X = 2;

    int count_x = std::count(vec.begin(), vec.end(), X);
    std::cout << "Число " << X << " встречается: " << count_x << " раз(а)\n";

    return 0;
}
//5
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    std::reverse(vec.begin(), vec.end());

    std::cout << "Развернутый вектор: ";
    for (int n : vec) {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    return 0;
}
//6
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {5, 2, 8, 1, 4};

    // по возрастанию
    std::sort(vec.begin(), vec.end());
    std::cout << "По возрастанию: ";
    for (int n : vec) std::cout << n << ' ';
    std::cout << '\n';

    // по убыванию
    std::sort(vec.begin(), vec.end(), [](int a, int b){ return b < a; });
    std::cout << "По убыванию: ";
    for (int n : vec) std::cout << n << ' ';
    std::cout << '\n';

    return 0;
}
//7
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 2, 4, 2, 5};
    int X = 2;

    // Удаление всех вхождений X
    vec.erase(std::remove(vec.begin(), vec.end(), X), vec.end());

    std::cout << "После удаления X: ";
    for (int n : vec) std::cout << n << ' ';
    std::cout << '\n';

    return 0;
}
//8
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {15, 3, 20, 7, 12, 25};

    // Удалить все элементы > 10
    vec.erase(std::remove_if(vec.begin(), vec.end(), [](int n){ return n > 10; }), vec.end());

    std::cout << "После удаления >10: ";
    for (int n : vec) std::cout << n << ' ';
    std::cout << '\n';

    return 0;
}
//9
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 2, 3, 4, 4, 5};

    // Сортируем для unique
    std::sort(vec.begin(), vec.end());
    auto last = std::unique(vec.begin(), vec.end());
    vec.erase(last, vec.end());

    std::cout << "Уникальные элементы: ";
    for (int n : vec) std::cout << n << ' ';
    std::cout << '\n';

    return 0;
}
//10
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int> squares(vec.size());

    std::transform(vec.begin(), vec.end(), squares.begin(), [](int n){ return n * n; });

    std::cout << "Квадраты: ";
    for (int n : squares) std::cout << n << ' ';
    std::cout << '\n';

    return 0;
}
//11
#include <iostream>
#include <vector>
#include <map>

int main() {
    std::vector<int> vec = {1, 2, 2, 3, 3, 3, 4};
    std::map<int, int> freq;

    for (int n : vec) {
        ++freq[n];
    }

    for (const auto& pair : freq) {
        std::cout << pair.first << ": " << pair.second << " раз(а)\n";
    }

    return 0;
}
//12
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 3, 3, 2, 2, 2, 4};
    std::map<int, int> freq;

    for (int n : vec) {
        ++freq[n];
    }

    auto max_pair = std::max_element(freq.begin(), freq.end(),
        [](const auto& a, const auto& b){ return a.second < b.second; });

    if (max_pair != freq.end()) {
        std::cout << "Наиболее частое число: " << max_pair->first
                  << " встречается " << max_pair->second << " раз(а)\n";
    }

    return 0;
}
//13
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap = {{1, "один"}, {2, "два"}};
    int key = 2;

    if (myMap.find(key) != myMap.end()) {
        std::cout << "Ключ найден\n";
    } else {
        std::cout << "Ключ не найден\n";
    }

    return 0;
}
//14
#include <iostream>
#include <map>
#include <sstream>
#include <string>

int main() {
    std::string text = "apple banana apple orange banana apple";

    std::istringstream iss(text);
    std::map<std::string, int> wordCount;
    std::string word;

    while (iss >> word) {
        ++wordCount[word];
    }

    std::cout << "Слова и их количество по алфавиту:\n";
    for (const auto& pair : wordCount) {
        std::cout << pair.first << ": " << pair.second << '\n';
    }

    return 0;
}
//15
#include <iostream>
#include <map>
#include <sstream>
#include <string>

int main() {
    std::string text = "apple banana apple orange banana apple";

    std::istringstream iss(text);
    std::map<std::string, int> wordCount;
    std::string word;

    while (iss >> word) {
        ++wordCount[word];
    }

    std::cout << "Слова и их количество по алфавиту:\n";
    for (const auto& pair : wordCount) {
        std::cout << pair.first << ": " << pair.second << '\n';
    }

    return 0;
}
//16
#include <iostream>
#include <stack>

int main() {
    std::stack<int> s;

    // Добавление
    s.push(10);
    s.push(20);
    s.push(30);

    // Верхний элемент
    std::cout << "Верхний элемент: " << s.top() << '\n';

    // Удаление
    s.pop();
    std::cout << "После pop, верхний элемент: " << s.top() << '\n';

    return 0;
}
//17
#include <iostream>
#include <queue>
#include <string>

int main() {
    std::queue<std::string> tasks;

    // Добавляем задачи
    tasks.push("Задача 1");
    tasks.push("Задача 2");
    tasks.push("Задача 3");

    // Обработка
    while (!tasks.empty()) {
        std::cout << "Обработка: " << tasks.front() << '\n';
        tasks.pop();
    }

    return 0;
}
