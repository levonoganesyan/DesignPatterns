#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<map>

class EventListener
{
    int number;
public:
    EventListener(int number)
        : number(number)
    {}
    virtual void Update(const std::string& data) = 0;
    virtual int GetNumber() const
    {
        return number;
    }
};
class LogEventListener : public EventListener
{
public:
    LogEventListener(int number)
        : EventListener(number)
    {}
    virtual void Update(const std::string& data) override
    {
        std::cout << "Log event update called with data = " << data << std::endl;
    }
};
class MailEventListener : public EventListener
{
public:
    MailEventListener(int number)
        : EventListener(number)
    {}
    virtual void Update(const std::string& data) override
    {
        std::cout << "Mail event update called with data = " << data << std::endl;
    }
};

class EventManager
{
    std::map<std::string, std::vector<std::shared_ptr<EventListener>>> listeners;
public:
    void Subscribe(const std::string& type, std::shared_ptr<EventListener> listener)
    {
        std::cout << "Listener " << listener->GetNumber()
            << " subscribed on " << type << std::endl;
        listeners[type].push_back(listener);
    }
    void Unsubscribe(const std::string& type, std::shared_ptr<EventListener> listener)
    {
        std::cout << "Listener " << listener->GetNumber()
            << " unsubscribed from " << type << std::endl;
        for (int i = 0; i < listeners[type].size(); ++i)
            if (listeners[type][i]->GetNumber() == listener->GetNumber())
                listeners[type].erase(listeners[type].begin() + i);
    }
    void Notify(const std::string& type, const std::string& data)
    {
        for (int i = 0; i < listeners[type].size(); ++i)
            listeners[type][i]->Update(data);
    }
};


class SomeStuff
{
    std::shared_ptr<EventManager> event_manager;
public:
    SomeStuff()
        : event_manager(std::make_shared<EventManager>())
    {}
    void DoStuff1()
    {
        event_manager->Notify("doStuff1", "I did stuff1");
    }
    void DoStuff2()
    {
        event_manager->Notify("doStuff2", "I did stuff2");
    }
    void Subscribe(const std::string& type, std::shared_ptr<EventListener> listener)
    {
        event_manager->Subscribe(type, listener);
    }
    void Unsubscribe(const std::string& type, std::shared_ptr<EventListener> listener)
    {
        event_manager->Unsubscribe(type, listener);
    }

};


void Test()
{
    SomeStuff* ss = new SomeStuff();
    std::shared_ptr<MailEventListener> mel1(std::make_shared<MailEventListener>(1));
    std::shared_ptr<MailEventListener> mel2(std::make_shared<MailEventListener>(2));
    std::shared_ptr<LogEventListener> lel(std::make_shared<LogEventListener>(3));
    ss->Subscribe("doStuff1", lel);
    ss->Subscribe("doStuff1", lel);
    ss->Subscribe("doStuff1", mel1);
    ss->Subscribe("doStuff1", mel2);
    ss->Subscribe("doStuff2", mel2);
    ss->DoStuff1();
    ss->DoStuff2();
}



