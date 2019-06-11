#pragma once

#include<iostream>
#include<cstdlib>

class GameObject
{
protected:
    int players_count;
    virtual void InitializeGame() = 0;
    virtual bool EndOfGame() = 0;
    virtual void MakeMove(int player_id) = 0;
    virtual void PrintWinner(int player_id) = 0;
public:
    virtual void Play(int players)
    {
        players_count = players;
        InitializeGame();

        int player_id = -1;
        while (!EndOfGame())
        {
            MakeMove(player_id);
            player_id = (player_id + 1) % players_count;
        }

        PrintWinner();
    }
};


class Monopoly : public GameObject
{
    virtual void InitializeGame()
    {
        std::cout << "Initializing Monopoly" << std::endl;
    }
    virtual bool EndOfGame()
    {
        return rand() % 10;
    }
    virtual void MakeMove(int player_id)
    {
        std::cout << "Player " << player_id << " make a move" << std::endl;
    }
    virtual void PrintWinner(int player_id)
    {
        std::cout << "Player " << player_id << " is won!" << std::endl;
    }
};


class Chess : public GameObject
{
    virtual void InitializeGame()
    {
        std::cout << "Initializing Chess" << std::endl;
    }
    virtual bool EndOfGame()
    {
        return rand() % 10;
    }
    virtual void MakeMove(int player_id)
    {
        std::cout << "Player " << player_id << " make a move" << std::endl;
    }
    virtual void PrintWinner(int player_id)
    {
        std::cout << "Player " << player_id << " is won!" << std::endl;
    }
};



void Test()
{
    GameObject* game1 = new Chess();
    game1->Play(2);


    GameObject* game2 = new Monopoly();
    game2->Play(10);

}


