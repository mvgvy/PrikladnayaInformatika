#include <iostream>
#include "safe_long_long_t.h"
#include "array23.h"
int main() {
    std::cout << "task1" <<std::endl;
        auto array = new Array(3);
        auto array_2 = array;
        std::cout<<array_2<<std::endl;
        std::cout<<array<<std::endl;

    std::cout << "task2"<< std::endl;
    safe_long_long_t a(15);
    std::cout << a + 15<< std::endl;;
    safe_long_long_t b(15);
    std::cout << a + b <<std::endl;
    std::cout << a * b <<std::endl;;
    std::cout << a / b <<std::endl;;
    std::cout << a - b <<std::endl;;
return 0;
}