#pragma once

#include<iostream>
#include<string>

class Notifier
{
public:
    virtual void write()
    {
        std::cout << "Notifier" << std::endl;
    }
};

class FacebookNotifier : public Notifier
{
    std::shared_ptr<Notifier> notifier;
public:
    FacebookNotifier(std::shared_ptr<Notifier> notifier)
        : notifier(notifier)
    {
    }
    virtual void write()
    {
        std::cout << "Facebook" << std::endl;
        notifier->write();
    }
};




class SlackNotifier : public Notifier
{
    std::shared_ptr<Notifier> notifier;
public:
    SlackNotifier(std::shared_ptr<Notifier> notifier)
        : notifier(notifier)
    {
    }
    virtual void write()
    {
        std::cout << "Slack" << std::endl;
        notifier->write();
    }
};


void Test()
{
    std::shared_ptr<Notifier> notifier = std::make_shared<Notifier>();
    notifier = std::make_shared<FacebookNotifier>(notifier);
    notifier = std::make_shared<SlackNotifier>(notifier);
    notifier->write();
}


