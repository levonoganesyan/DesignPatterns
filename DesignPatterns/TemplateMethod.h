#pragma once


class GameObject
{
protected:
    int players_count;
public:
    virtual void InitializeGame() = 0;
    virtual bool EndOfGame() = 0;
    virtual void MakeMove(int player_id) = 0;
    virtual void PrintWinner() = 0;
    virtual void Play(int players)
    {
        players_count = players;
        InitializeGame();

        int player_id = 0;
        while (!EndOfGame())
        {
            MakeMove(player_id);
            player_id = (player_id + 1) % players_count;
        }

        PrintWinner();
    }
};

