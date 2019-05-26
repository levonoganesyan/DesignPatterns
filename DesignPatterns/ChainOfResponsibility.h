#pragma once


class CriminalAction
{
    int complexity;
    const char* description;
public:
    CriminalAction(int complexity, const char* description)
        : complexity(complexity)
        , description(description)
    {
    }
};


