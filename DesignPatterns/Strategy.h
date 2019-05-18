#pragma once

#include<functional>

template <typename T>
class Operation
{
    std::function<T(T, T)> m_method;
};
