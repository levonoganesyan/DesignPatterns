#pragma once

class Chair
{
    //
};

class ModernChair : public Chair
{
    //
};

class OldChair : public Chair
{
    //
};


class Table
{
    //
};

class ModernTable : public Table
{
    //
};

class OldTable : public Table
{
    //
};

class Factory
{
public:
    virtual Chair* GetChair() = 0;
    virtual Table* GetTable() = 0;
};

class ModernFactory : public Factory
{
public:
    virtual ModernChair* GetChair()
    {
        return new ModernChair;
    }
    virtual ModernTable* GetTable()
    {
        return new ModernTable;
    }
};

class OldFactory : public Factory
{
public:
    virtual OldChair* GetChair()
    {
        return new OldChair;
    }
    virtual OldTable* GetTable()
    {
        return new OldTable;
    }
};


class Application
{
    Factory* factory;
public:
    Application(Factory* factory)
        : factory(factory) {}

    void CreateChair()
    {
        Chair* chair = factory->GetChair();
        // some work with chair
    }
    void CreateTable()
    {
        Table* table = factory->GetTable();
        // some work with table 
    }
};


void ApplicationConfig() // start of program
{
    Factory* factory;
    if (/*need to create old factory*/1)
        factory = new OldFactory;
    else
        factory = new ModernFactory;
    Application app(factory);
    // some work with app
}












