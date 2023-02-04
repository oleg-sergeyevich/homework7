#include "ArrayExc.h"
#include <iostream>

void Bad::Show()
{
    std::cerr << "Error: " << m_bad << std::endl;
}

void bad_length(int length) // функция для проверки допустимости значения размера массива
{
    if (length < 0 || length > 100)
    {
        throw Bad("недопустимый размер массива"); // генерирует исключение
    }
}

void bad_range(int index, int length) // функция для проверки допустимости значения индекса элемента в массиве
{
    if (index < 0 || index > length)
    {
        throw Bad("недопустимый индекс - выход за пределы массива"); // генерирует исключение
    }
}