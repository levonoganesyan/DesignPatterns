#pragma once

#include<string>

class StateContext;

class State
{
    std::string name;
public:
    State(const std::string& name)
        : name(name) {}
    std::string GetName()
    {
        return name;
    }
    virtual void Freeze(StateContext*) = 0;
    virtual void Heat(StateContext*) = 0;
};

class SolidState : public State
{
public:
    SolidState() : State("solid") {}
    virtual void Freeze(StateContext* state);
    virtual void Heat(StateContext*) = 0;
};





