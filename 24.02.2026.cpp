//1
#include <iostream>


int* createArray(int size);

int main()
{
    int* data = createArray(10);

    
    for (int i = 0; i < 5; ++i) {
        data[i] = i * 10;
        std::cout << "data[" << i << "] = " << data[i] << std::endl;
    }

    
    delete[] data;
    data = nullptr; 

    return 0; 
}

int* createArray(int size)
{
    int* arr = new int[size];
    return arr;
}

//4
#include <iostream>
void change(int& x)  
{
    x = 100;        
}

int main()
{
    int a = 5;
    change(a);        
    std::cout << a;
    return 0;
}
