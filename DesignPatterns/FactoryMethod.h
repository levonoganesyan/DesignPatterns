#pragma once

class Transport
{
public:
    virtual void Delivery() = 0;
};

class Ship : public Transport
{
public:
    virtual void Delivery()
    {
        // some ship job here
    }
};

class Truck : public Transport
{
public:
    virtual void Delivery()
    {
        // some Trunk job here
    }
};

class Logistic
{
public:
    virtual void Send() = 0;
};


class RoadLogistic : public Logistic
{
public:
    virtual void Send()
    {
        Truck * t = new Truck();
        t->Delivery();
    }
};

class SeaLogistic : public Logistic
{
public:
    virtual void Send()
    {
        Ship* s = new Ship();
        s->Delivery();
    }
};


class Application
{
    Logistic* l;
public:
    Application(bool sea)
    {
        if (sea)
            l = new SeaLogistic();
        else
            l = new RoadLogistic();
    }
    void Send()
    {
        l->Send();
    }





};









