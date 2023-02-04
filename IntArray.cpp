#include "IntArray.h"
#include <iostream>

IntArray::IntArray(int length) : m_length(length)
{
    m_data = new int[m_length] {};
}

IntArray::IntArray(const IntArray& arr)
{
    reallocate(arr.getLength());

    for (int index = 0; index < m_length; ++index)
    {
        m_data[index] = arr.m_data[index];
    }
}

void IntArray::erase()
{
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
}

int& IntArray::operator[](int index)
{
    bad_range(index, m_length);
    return m_data[index];
}

void IntArray::reallocate(int newLength)
{
    erase();

    if (newLength <= 0)
    {
        return;
    }

    m_data = new int[newLength];
    m_length = newLength;
}

void IntArray::resize(int newLength)
{
    if (newLength == m_length)
    {
        return;
    }

    if (newLength == 0)
    {
        erase();
        return;
    }

    bad_length(newLength);

    int* data{ new int[newLength] };

    if (m_length > 0)
    {
        int elementsToCopy{ (newLength > m_length) ? m_length : newLength };

        for (int index = 0; index < elementsToCopy; ++index)
        {
            data[index] = m_data[index];
        }
    }

    delete[] m_data;
    m_data = data;
    m_length = newLength;
}

IntArray& IntArray::operator=(const IntArray& arr)
{
    if (&arr == this)
    {
        return *this;
    }

    reallocate(arr.getLength());

    for (int index = 0; index < m_length; ++index)
    {
        m_data[index] = arr.m_data[index];
    }

    return *this;
}

void IntArray::insertBefore(int value, int index)
{
    bad_range(index, m_length);

    int* data{ new int[m_length + 1] };

    for (int before = 0; before < index; ++before)
    {
        data[before] = m_data[before];
    }

    data[index] = value;

    for (int after = index; after < m_length; ++after)
    {
        data[after + 1] = m_data[after];
    }

    delete[] m_data;
    m_data = data;
    ++m_length;
}

void IntArray::remove(int index)
{
    bad_range(index, m_length);

    if (m_length == 1)
    {
        erase();
        return;
    }

    int* data{ new int[m_length - 1] };

    for (int before = 0; before < index; ++before)
    {
        data[before] = m_data[before];
    }

    for (int after = index + 1; after < m_length; ++after)
    {
        data[after - 1] = m_data[after];
    }

    delete[] m_data;
    m_data = data;
    --m_length;
}

void IntArray::add(int value, int index)
{
    bad_range(index, m_length);
    m_data[index] = value;
}

void IntArray::insertAtBeginning(int value)
{
    insertBefore(value, 0);
}

void IntArray::insertAtEnd(int value)
{
    insertBefore(value, m_length);
}

int IntArray::getLength() const
{
    return m_length;
}

IntArray::~IntArray()
{
    delete[] m_data;
    std::cout << "Destruktor" << '\n';
}