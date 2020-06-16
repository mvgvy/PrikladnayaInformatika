#include <iostream>
#include "safe_long_long_t.h"
#include "array.h"
int main() {
    std::cout << "task1" <<std::endl;
    Array arr1(4);
    Array arr2(3);

    arr1.display();
    arr2.display();

    bool b1 = arr1 > arr2;
    bool b2 = arr1 < arr2;
    bool b3 = arr1 == arr2;
    bool b4 = arr1 != arr2;

    printf("B1 = %d\nB2 = %d\nB3 = %d\nB4 = %d\n", b1, b2, b3, b4);

    Array arr3 = arr1 + arr2;
    std::cout << arr3.getSize() << std::endl;
    arr3.display();
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