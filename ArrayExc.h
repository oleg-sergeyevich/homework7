#pragma once
#include <string>

class Bad
{
public:
    Bad(const std::string& bad) : m_bad(bad) {}

    void Show();

    ~Bad() = default;

private:
    std::string m_bad;
};

void bad_length(int length); // функция для проверки допустимости значения размера массива

void bad_range(int index, int length); // функция для проверки допустимости значения индекса элемента в массиве