#include "ArrayExc.h"
#include <iostream>

void Bad::Show()
{
    std::cerr << "Error: " << m_bad << std::endl;
}

void bad_length(int length) // ������� ��� �������� ������������ �������� ������� �������
{
    if (length < 0 || length > 100)
    {
        throw Bad("������������ ������ �������"); // ���������� ����������
    }
}

void bad_range(int index, int length) // ������� ��� �������� ������������ �������� ������� �������� � �������
{
    if (index < 0 || index > length)
    {
        throw Bad("������������ ������ - ����� �� ������� �������"); // ���������� ����������
    }
}