#pragma once

#include<iostream>
#include<string>
#include<memory>

struct Data
{
    int data;
    Data()
        : data(0)
    {

    }
};

class IDatabaseAccessor
{
public:
    virtual Data getData(const std::string& request) = 0;
};

class DatabaseAccessor : public IDatabaseAccessor
{
    std::string db_name;
public:
    DatabaseAccessor(const std::string& db_name)
        : db_name(db_name)
    {}
    virtual Data getData(const std::string& request)
    {
        Data d;
        // populate from database "db_name" into d
        d.data = 10;
        return d;
    }
};


class DatabaseAccessorProxy : public IDatabaseAccessor
{
    std::shared_ptr<DatabaseAccessor> accessor;
public:
    DatabaseAccessorProxy(const std::string& db_name)
        : accessor(std::make_shared<DatabaseAccessor>(db_name))
    {}
    virtual Data getData(const std::string& request)
    {
        std::cout << "Proxy class logged request" << std::endl;
        return accessor->getData(request);
    }
};

void Test()
{
    std::shared_ptr<IDatabaseAccessor> da1 =
        std::make_shared<DatabaseAccessor>("name1");
    Data d1 = da1->getData("some request");
    if (d1.data == 10)
    {
        std::cout << "Request processed right" << std::endl;
    }

    std::shared_ptr<IDatabaseAccessor> da2 =
        std::make_shared<DatabaseAccessorProxy>("name2");
    Data d2 = da2->getData("some request");
    if (d2.data == 10)
    {
        std::cout << "Request processed right" << std::endl;
    }

}


