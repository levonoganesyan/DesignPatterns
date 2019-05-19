#pragma once

#include<functional>

template <typename T>
class Operation
{
    std::function<T(const T&, const T&)> m_method;
public:
    void setMethod(const std::function<T(const T&, const T&)>& method)
    {
        m_method = method;
    }
    T Execute(const T& a, const T& b)
    {
        return m_method(a, b);
    }
};

int plus(int a, int b)
{
    return a + b;
}

int minus(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}


