#pragma once

#include<string>
#include<vector>

class Editor
{
public:
    std::string m_text;
    std::string GetSelection() { /* ... */ }
    void DeleteSelection() { /* ... */ }
    void ReplaceSelection(const std::string& text) { /* ... */ }
};

class CommandHistory;
class Command;

class Application
{
public:
    std::string m_clipboard;
    std::vector<Editor> m_editors;
    Editor m_active_editor;
    CommandHistory* m_command_history;

    void CreateUI();
    void ExecuteCommand(std::shared_ptr<Command> c);
    void Undo();
};

class Command
{
protected:
    Application* m_app;
    Editor* m_editor;
    std::string m_text;
public:
    Command(Application* app, Editor* editor)
        : m_app(app)
        , m_editor(editor)
    {
    }
    void Save()
    {
        m_text = m_editor->m_text;
    }
    void Undo()
    {
        m_editor->m_text = m_text;
    }
    virtual bool Execute() = 0;
};
class CopyCommand : public Command
{
public:
    virtual bool Execute() override
    {
        m_app->m_clipboard = m_editor->GetSelection();
        return false;
    }
};
class CutCommand : public Command
{
public:
    virtual bool Execute() override
    {
        Save();
        m_app->m_clipboard = m_editor->GetSelection();
        m_editor->DeleteSelection();
        return true;
    }
};

class PasteCommand : public Command
{
public:
    virtual bool Execute() override
    {
        Save();
        m_editor->ReplaceSelection(m_app->m_clipboard);
        return true;
    }
};
class UndoCommand : public Command
{
public:
    virtual bool Execute() override
    {
        m_app->Undo();
        return false;
    }
};

class CommandHistory
{
    std::vector<std::shared_ptr<Command>> commands;
public:
    void push(std::shared_ptr<Command> c)
    {
        commands.push_back(c);
    }
    std::shared_ptr<Command> pop()
    {
        if (commands.empty())
        {
            return std::shared_ptr<Command>(nullptr);
        }
        std::shared_ptr<Command> c = commands.back();
        commands.pop_back();
        return c;
    }
};


void Application::CreateUI()
{
    // ...
    /*
    copy = []() {
        executeCommand(new CopyCommand(this, activeEditor));
    };
    copyButton.setCommand(copy);
    shortcuts.onKeyPress("Ctrl+C", copy)



    cut = []() {
        executeCommand(new CutCommand(this, activeEditor));
    };
    cutButton.setCommand(cut);
    shortcuts.onKeyPress("Ctrl+X", cut);



    paste = []() {
        executeCommand(new PasteCommand(this, activeEditor));
    };
    pasteButton.setCommand(paste);
    shortcuts.onKeyPress("Ctrl+V", paste);

    undo = []() {
        executeCommand(new UndoCommand(this, activeEditor));
    };
    undoButton.setCommand(undo);
    shortcuts.onKeyPress("Ctrl+Z", undo);
    */
}

void Application::ExecuteCommand(std::shared_ptr<Command> c)
{
    if (c->Execute())
        m_command_history->push(c);
}

void Application::Undo()
{
    auto c = m_command_history->pop();
    if (c != nullptr)
        c->Undo();
}


