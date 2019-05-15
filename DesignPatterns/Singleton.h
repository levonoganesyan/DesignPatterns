#pragma once

#include<iostream>

class Singleton
{
    static Singleton* current_this;
    int data;
    Singleton(int data)
        : data(data)
    {}
public:
    static Singleton* getInstance()
    {
        if (!current_this)
        {
            current_this = new Singleton(0);
        }
        return current_this;
    }
};

Singleton* Singleton::current_this = nullptr;


void Test()
{
    std::cout << (Singleton::getInstance() == Singleton::getInstance()) << std::endl;
}
