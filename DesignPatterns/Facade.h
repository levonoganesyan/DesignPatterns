#pragma once

#include<iostream>
#include<exception>
#include<string>
#include<memory>

class Target
{
public:
    virtual void send(const std::string& address)
    {
        throw std::logic_error("This target cannot send anything\n");
    }
    virtual void hire(const std::string& employee_name)
    {
        throw std::logic_error("This target cannot hire anyone\n");
    }
    virtual void add(const std::string& product)
    {
        throw std::logic_error("This target cannot add any product\n");
    }
};

class Person : public Target
{
public:
    void send(const std::string& address)
    {
        std::cout << "Person send package to " << address << std::endl;
    }
};

class Amazon : public Target
{
public:
    void send(const std::string& address)
    {
        std::cout << "Amazon send package to " << address << std::endl;
    }
    void hire(const std::string& employee_name)
    {
        std::cout << "Amazon hired " << employee_name << std::endl;
    }
    void add(const std::string& product)
    {
        std::cout << "Amazon added " << product << std::endl;
    }
};

class Google : public Target
{
public:
    void hire(const std::string& employee_name)
    {
        std::cout << "Google hired " << employee_name << std::endl;
    }
};

class Market : public Target
{
public:
    void add(const std::string& product)
    {
        std::cout << "Amazon added " << product << std::endl;
    }
};


class Facade
{
    std::shared_ptr<Amazon> amazon;
    std::shared_ptr<Person> person;
    std::shared_ptr<Google> google;
    std::shared_ptr<Market> market;
    void send(const std::string& address)
    {
        std::cout << "Amazon send package to " << address << std::endl;
    }
    void hire(const std::string& employee_name)
    {
        std::cout << "Amazon hired " << employee_name << std::endl;
    }
    void add(const std::string& product)
    {
        std::cout << "Amazon added " << product << std::endl;
    }
public:
    Facade()
        : amazon(std::make_shared<Amazon>())
        , person(std::make_shared<Person>())
        , google(std::make_shared<Google>())
        , market(std::make_shared<Market>())
    {

    }
    void request(const std::string& type,
        const std::string& from,
        const std::string& data)
    {
        std::shared_ptr<Target> target;
        if (from == "amazon")
            target = amazon;
        else if (from == "market")
            target = market;
        else if (from == "person")
            target = person;
        else if (from == "google")
            target = google;

        try
        {
            if (type == "add")
                target->add(data);
            else if (type == "hire")
                target->hire(data);
            else if (type == "send")
                target->send(data);
        }
        catch (const std::exception& ex)
        {
            std::cout << ex.what() << std::endl;
        }
    }
};

void Test()
{
    Facade f;
    f.request("send", "google", "product");
    f.request("send", "amazon", "me");
}

