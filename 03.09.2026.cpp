//1
 #include <iostream>

int main()
{
	int age;
	int drivingexp;
	std::cout << "your age:";
	std::cin >> age;
	std::cout << "your driving experience: ";
	std::cin >> drivingexp;

	if (age < 18) { std::cout << "Access denied"; }
	else if (age > 18 && drivingexp < 3) { std::cout << "Access is permitted, but at a higher rate"; }
	else if (age > 18 && drivingexp > 3) { std::cout << "Access granted, standard rate"; }
	else { std::cout << "error"; }

//2
#include <iostream>
int main()
{
	double num1, num2;
	char operation;

	std::cout << "enter first number: ";
	std::cin >> num1;
	std::cout << "enter operation +,-,/,*: ";
	std::cin >> operation;
	std::cout << "enter second number: ";
	std::cin >> num2;

	switch (operation) {
	case '+':
		std::cout << "Result: " << num1 + num2 << std::endl;
		break;
	case '-':
		std::cout << "Result: " << num1 - num2 << std::endl;
		break;
	case '*':
		std::cout << "Result: " << num1 * num2 << std::endl;
		break;
	case '/':
		if (num2 != 0) {
			std::cout << "Result: " << num1 / num2 << std::endl;
		}
		else {
			std::cout << "Error";
		}
	}
}
//3
#include <iostream>
int main() 
{
	int sum = 0;

	for (int i = 1; i <= 100; i += 2) {
		sum += i;
	}
	std::cout << "the sum of all odd numbers in the range from 1 to 100: "<< sum<< std::endl;

    int count = 0;
    int number = 0;

    std::cout << "enter number (zero for stop): " << std::endl;
    while (std::cin >> number && number != 0) {
        count++;
    }

    std::cout << "a total of numbers were entered: " << count << std::endl;
}
//4
#include <iostream>

int main() {
    
    int arr[10] = { 12, 45, 5, 23, 50, 34, 19, 42, 8, 31 };

    int maxElement = arr[0];
    int maxIndex = 0;

   
    for (int i = 1; i < 10; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
            maxIndex = i;
        }
    }

    
    std::cout << "Max element: " << maxElement << std::endl;
    std::cout << "index element: " << maxIndex << std::endl;

    return 0;
}

//5
#include <iostream>

int main() {
    
    int a = 5;
    int b = 10;

   
    int* ptrA = &a;
    int* ptrB = &b;

    
    int temp = *ptrA; 
    *ptrA = *ptrB;    
    *ptrB = temp;     

    
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    return 0;
}

//6
#include <iostream>

bool isPrime(int n) {
    if (n <= 1) return false; 

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true; 
}

int main() {

    int number;
    std::cout << "enter the number: ";
    std::cin >> number;

    if (isPrime(number)) {
        std::cout << "The number is prime " << std::endl;
    }
    else {
        std::cout << "The number is composite" << std::endl;
    }

    return 0;
}

