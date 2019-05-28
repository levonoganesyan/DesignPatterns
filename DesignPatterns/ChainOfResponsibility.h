#pragma once


class CriminalAction
{
    int complexity;
    const char* description;
public:
    CriminalAction(int complexity, const char* description)
        : complexity(complexity)
        , description(description)
    {
    }
    int GetComplexity() const
    {
        return complexity;
    }
    const char* GetDescription() const
    {
        return description;
    }
};

class Policeman
{
protected:
    int deduction;
    Policeman* next;
    virtual void investigation(const char* description) {};
public:
    Policeman(int deduction)
        : deduction(deduction)
    {}

    virtual ~Policeman() 
    {
        if (next)
            delete next;
    }

};

