#pragma once

#include<functional>
#include<string>


class Operation
{
public:
    virtual int execute(int a, int b) = 0;
};


class Plus : public Operation
{
public:
    virtual int execute(int a, int b)
    {
        return a + b;
    }
};

class Minus : public Operation
{
public:
    virtual int execute(int a, int b)
    {
        return a - b;
    }
};

class Multiply : public Operation
{
public:
    virtual int execute(int a, int b)
    {
        return a * b;
    }
};


class Expression
{
    Operation* m_op;
public:
    void setMethod(Operation* op)
    {
        m_op = op;
    }
    int execute(int a, int b)
    {
        return m_op->execute(a, b);
    }
};



void Test()
{
    std::string operation = "plus";
    int a = 10, b = 5;
    Expression* expr = new Expression;
    if (operation == "plus")
    {
        expr->setMethod(new Plus);
    }
    else if (operation == "minus")
    {
        expr->setMethod(new Minus);
    }
    else if (operation == "multiply")
    {
        expr->setMethod(new Multiply);
    }
    std::cout << expr->execute(a, b);

}

