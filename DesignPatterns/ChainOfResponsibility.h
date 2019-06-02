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
        , next(nullptr)
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

class PolicemanB : public Policeman
{
    void investigation(const char * desc)
    {
        std::cout << "PolicemanB in investigating crime " << desc << std::endl;
    }
public:
    PolicemanB(int deduction)
        : Policeman(deduction)
    {
    }
};

class PolicemanC : public Policeman
{
    void investigation(const char * desc)
    {
        std::cout << "PolicemanC in investigating crime " << desc << std::endl;
    }
public:
    PolicemanC(int deduction)
        : Policeman(deduction)
    {
    }
};


void Test()
{
    Policeman* p = new PolicemanA(3);
    p->SetNext(new PolicemanB(5))->SetNext(new PolicemanC(7));

    p->investigate(new CriminalAction(4, "1"));
    p->investigate(new CriminalAction(3, "2"));
    p->investigate(new CriminalAction(6, "3"));
    p->investigate(new CriminalAction(10, "4"));

}

