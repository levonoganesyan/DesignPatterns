#pragma once
#include<iostream>

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

    Policeman* SetNext(Policeman* p)
    {
        next = p;
        return next;
    }

    void investigate(CriminalAction* crime)
    {
        if (deduction >= crime->GetComplexity())
        {
            investigation(crime->GetDescription());
        }
        else
        {
            if (next)
            {
                next->investigate(crime);
            }
            else
            {
                std::cout << "No one can investigate this." << std::endl;
            }
        }
    }
};

class PolicemanA : public Policeman
{
    void investigation(const char * desc)
    {
        std::cout << "PolicemanA in investigating crime " << desc << std::endl;
    }
public:
    PolicemanA(int deduction)
        : Policeman(deduction)
    {
    }
};

