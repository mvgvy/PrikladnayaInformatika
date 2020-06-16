#include <iostream>
#include "array.h"

Array::Array()
{
    this->n = 1;
    arr = new int[this->n];
    for (int i = 0; i < this->n; i++)
    {
        this->arr[i] = i + 1;
    }
}
Array::Array(int n)
{
    this->n = n;
    arr = new int[this->n];
    for (int i = 0; i < this->n; i++)
    {
        this->arr[i] = i + 1;
    }
}
void Array::delete_1(Array)
{
        delete[] arr;
}
int Array::getSize()
{
    return this->n;
}
void Array::display()
{
    for (int i = 0; i < this->n; i++)
    {
        std::cout << this->arr[i] << " ";
    }
    std::cout << std::endl;
}
void Array::addElem(int element)
{
    this->arr[n] = element;
    this->n++;
}
Array Array::operator + (Array mas)
{
    Array result(this->n + mas.n);
    int k = 0;
    for (int i = 0; i < this->n; i++)
    {
        result.arr[k++] = this->arr[i];
    }
    for (int i = 0; i < mas.n; i++)
    {
        result.arr[k++] = mas.arr[i];
    }

    return result;
}
bool Array::operator == (Array mas)
{
    return (this->n == mas.n);
}
bool Array::operator != (Array mas)
{
    return (this->n != mas.n);
}
bool Array::operator > (Array mas)
{
    return (this->n > mas.n);
}
bool Array::operator < (Array mas)
{
    return (this->n < mas.n);
}
