#pragma once
#include "ArrayExc.h"

class IntArray
{
public:
    IntArray() = default;

    IntArray(int length);

    IntArray(const IntArray& arr);

    void erase();

    int& operator[](int index);

    void reallocate(int newLength);

    void resize(int newLength);

    IntArray& operator=(const IntArray& arr);

    void insertBefore(int value, int index);

    void remove(int index);

    void add(int value, int index);

    void insertAtBeginning(int value);

    void insertAtEnd(int value);

    int getLength() const;

    ~IntArray();

private:
    int m_length = 0;
    int* m_data = nullptr;
};