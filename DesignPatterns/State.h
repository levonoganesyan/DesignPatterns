#pragma once

#include<string>
#include<iostream>

class State;

class StateContext
{
private:
    State* state;
    StateContext(State* state)
        : state(state) {}

    void Freeze()
    {
        state->Freeze(this);
    }
    void Heat()
    {
        state->Heat(this);
    }

    void SetState(State* s)
    {
        state = s;
    }    
    State* GetState()
    {
        return state;
    }

    ~StateContext()
    {
        delete state;
    }
};

class SolidState : public State
{
public:
    SolidState() : State("solid") {}
    virtual void Freeze(StateContext* state)
    {
        std::cout << "Nothing happened" << std::endl;
    }
    virtual void Heat(StateContext* state)
    {
        state.set
    }
};




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


