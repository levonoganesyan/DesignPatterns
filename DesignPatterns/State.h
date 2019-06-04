#pragma once

#include<string>

class StateContext;

class State
{
    virtual std::string GetName() = 0;
    virtual void freeze(StateContext*) = 0;
    virtual void heat(StateContext*) = 0;
};

class SolidState
{
private:
    std::string name;
public:
    SolidState() : name("solid") {}
};





