#pragma once


// 1
template <class T>
class Copyable
{
public:
    virtual T Clone() = 0;
};

class A : public Copyable<A>
{
    A Clone() override
    {
        return A();
    }
};


// 2
class B
{
public:
    virtual B* Clone() = 0;
};

class D : public B
{
public:
    virtual D* Clone() override
    {
        return new D(*this);
    }
};

void Test()
{
    B* d = new D();
    D* d_clone = dynamic_cast<D*>(d->Clone());
}


