#pragma once
#include<memory>
class Device
{
    bool on;
    int channel;
    int volume;
public:
    virtual bool IsEnabled()
    {
        return on;
    }
    virtual void TurnOn()
    {
        on = true;
    }
    virtual void TurnOff()
    {
        on = false;
    }
    virtual void SetVolume(int v)
    {
        volume = v;
    }
    virtual int GetVolume()
    {
        return volume;
    }
    virtual void SetChannel(int ch)
    {
        channel = ch;
    }
    virtual int GetChannel()
    {
        return channel;
    }

};

class TV : public Device
{
    // 
};


class Radio : public Device
{
    // 
};


class Remote
{
protected:
    std::shared_ptr<Device> device;
public:
    Remote(std::shared_ptr<Device> device)
        : device(device)
    {
        
    }

    void TogglePower()
    {
        if (device->IsEnabled())
        {
            device->TurnOff();
        }
        else
        {
            device->TurnOn();
        }
    }
    void IncreaseVolume()
    {
        device->SetVolume(device->GetVolume() + 10);
    }
    void IncreaseChannel()
    {
        device->SetChannel(device->GetChannel() + 1);
    }
    // 
};

class AdvancedRemote : public Remote
{
public: 
    AdvancedRemote(std::shared_ptr<Device> device)
        : Remote(device)
    {

    }
    void Mute()
    {
        device->SetVolume(0);
    }
};


void Test()
{
    std::shared_ptr<Device> device = std::make_shared<TV>();
    Remote remote(device);
    remote.IncreaseChannel();
    AdvancedRemote adv_remote(device);
    adv_remote.Mute();
}




