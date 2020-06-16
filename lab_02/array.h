#pragma once

class Array
{
private:
    int *arr;
    int n;
public:
    Array();
    Array(int n);
    int getSize();
    void delete_1(Array mas);
    void display();
    void addElem(int element);
    Array operator + (Array mas);
    bool operator == (Array mas);
    bool operator != (Array mas);
    bool operator > (Array mas);
    bool operator < (Array mas);
};