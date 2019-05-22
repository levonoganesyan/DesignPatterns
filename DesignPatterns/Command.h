#pragma once

#include<string>
#include<vector>

class Editor
{
    std::string m_text;
public:
    std::string GetSelection() { /* ... */ }
    std::string DeleteSelection() { /* ... */ }
    std::string ReplaceSelection() { /* ... */ }
};

class Command;

class Application
{
    std::string m_clipboard;
    std::vector<Editor> m_editors;
    Editor m_active_editor;
    Command* m_command_history;
public:
    void CreateUI();
    void ExecuteCommand();
    void Undo();
};

class Command
{
protected:
    Application* m_app;
    Editor* m_editor;
};



