#pragma once

#include<memory>
#include<string>

class Mediator
{
public:
    virtual void notify(std::shared_ptr<Component> c, const std::string& event) = 0;
};

class Component 
{
protected:
    std::shared_ptr<Mediator> m_dialog;
public:
    Component(std::shared_ptr<Mediator> dialog)
        : m_dialog(dialog)
    {}
    void click()
    {
        m_dialog->notify(std::make_shared<Component>(this), "click");
    }
    void keypress()
    {
        m_dialog->notify(std::make_shared<Component>(this), "keypress");
    }
};


class Button : public Component {};
class Textbox : public Component {};
class Checkbox : public Component 
{
public:
    void click()
    {
        m_dialog->notify(std::make_shared<Component>(this), "check");
    }
};

class AuthenticationDialog : public Mediator
{
    std::string m_title;
    std::shared_ptr<Checkbox> m_login_or_register_chk_bx;
    std::shared_ptr<Textbox> m_login_username;
    std::shared_ptr<Textbox> m_login_password;
    std::string m_registration_username;
    std::string m_registration_password;
    std::shared_ptr<Textbox> m_registration_email;
    std::shared_ptr<Button> m_ok_btn;
    std::shared_ptr<Button> m_cancel_btn;
public:
    AuthenticationDialog()
    {
        // initialising all members
    }
    void notify(std::shared_ptr<Component> sender, const std::string& event)
    {
        if (sender == m_login_or_register_chk_bx && event == "check")
        {
            /*
            if(m_login_or_register_chk_bx.checked)
            {
                title = "Log in";
            }
            else
            {
                title = "Register";
            }
            */
        }
        if (sender == m_ok_btn && event == "click")
        {
            /*
            if (m_login_or_register.checked)
            {
                // try to find used
                if (!found)
                    // show error
            }
            else
            {
                // Create account, etc...
            }
            */
        }
    }
};

