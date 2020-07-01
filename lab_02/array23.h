#include<iostream>
template <class T>
class Array{
private:
    T *m_array;
    size_t m_size;
public:
    Array():
            m_size(0), m_array(nullptr)
    {}
    Array(T const & arg)
    {
        m_size = 1;
        m_array = new T[1];
        m_array[0] = arg;
    }

    Array(Array const & value)
    {
        m_size = value.m_size;
        m_array = new T[m_size + 1];
        for (size_t i = 0; i < m_size; i++)
        {
            m_array[i] = value.m_array[i];
        }
    }

    ~Array()
    {
        delete [] m_array;
    }

    Array & operator=(Array const & other)
    {
        delete [] m_array;
        m_array = new T[other.m_size + 1];
        memcpy(m_array, other.m_array, other.m_size + 1);
        m_size = other.m_size;
        return *this;
    }

};
