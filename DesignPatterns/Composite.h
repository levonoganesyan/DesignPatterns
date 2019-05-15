#pragma once

#include<iostream>
#include<vector>
#include<memory>
#include<string>

class Object
{
public:
    virtual void AddObject(std::shared_ptr<Object> obj)
    {
        throw std::runtime_error("This must be redefined only in Box\n");
    }
};

class Box : public Object
{
    std::vector<std::shared_ptr<Object>> m_all;
public:
    void AddObject(std::shared_ptr<Object> obj) override
    {
        m_all.push_back(obj);
    }
};

struct Element : public Object
{
    std::string name;
    Element (const std::string& name)
        : name(name)
    {}
};

void Test()
{
    std::shared_ptr<Object> table(std::make_shared<Element>("table"));
    std::shared_ptr<Object> stool(std::make_shared<Element>("stool"));
    std::shared_ptr<Object> box_with_table(std::make_shared<Box>());
    box_with_table->AddObject(table);
    std::shared_ptr<Object> box_with_table_and_stool(std::make_shared<Box>());
    box_with_table_and_stool->AddObject(box_with_table);
    box_with_table_and_stool->AddObject(stool);

}

