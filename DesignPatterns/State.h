#pragma once

#include<string>
#include<iostream>

class State;
class SolidState;
class LiquidState;
class GasState;

class StateContext
{
private:
    State* state;
public:
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
    SolidState() : State("Solid") {}
    virtual void Freeze(StateContext* state);
    virtual void Heat(StateContext* state);
};
class LiquidState : public State
{
public:
    LiquidState() : State("Liquid") {}
    virtual void Freeze(StateContext* state);
    virtual void Heat(StateContext* state);
};
class GasState : public State
{
public:
    GasState() : State("Gas") {}
    virtual void Freeze(StateContext* state);
    virtual void Heat(StateContext* state);
};

void SolidState::Freeze(StateContext* state)
{
    std::cout << "Nothing happened";
}
void SolidState::Heat(StateContext* state)
{
    state->SetState(new LiquidState());
}

void LiquidState::Freeze(StateContext* state)
{
    state->SetState(new SolidState());
}
void LiquidState::Heat(StateContext* state)
{
    state->SetState(new GasState());
}

void GasState::Freeze(StateContext* state)
{
    state->SetState(new LiquidState());
}
void GasState::Heat(StateContext* state)
{
    std::cout << "Nothing happened";
}


