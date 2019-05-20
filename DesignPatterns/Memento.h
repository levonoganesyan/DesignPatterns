#pragma once

#include<vector>
#include<iostream>
#include<cstdlib>

class game2048;

class Snapshot
{
    std::vector<std::vector<int>> m_matrix;
    game2048* m_game;
public:
    Snapshot(game2048* game, const std::vector<std::vector<int>>& matrix);
    void Restore();

};

class game2048
{
    std::vector<std::vector<int>> m_matrix;
public:
    game2048()
        : m_matrix(4, std::vector<int>(4))
    {}
    void Randomize()
    {
        for (int i = 0; i < m_matrix.size(); ++i)
            for (int j = 0; j < m_matrix[i].size(); ++j)
                m_matrix[i][j] = rand() % 2;
    }
    void Show()
    {
        for (int i = 0; i < m_matrix.size(); ++i, std::cout << std::endl)
            for (int j = 0; j < m_matrix[i].size(); ++j)
                std::cout << m_matrix[i][j] << " ";
        std::cout << std::endl;
    }
    Snapshot* createSnapshot()
    {
        return new Snapshot(this, m_matrix);
    }
    void setMatrix(const std::vector<std::vector<int>>& matrix)
    {
        m_matrix = matrix;
    }
};

Snapshot::Snapshot(game2048* game, const std::vector<std::vector<int>>& matrix)
    : m_matrix(matrix)
    , m_game(game)
{

}
void Snapshot::Restore()
{
    m_game->setMatrix(m_matrix);
}


void Test()
{
    game2048 g;
    g.Randomize();
    g.Show();
    auto snap = g.createSnapshot();
    g.Randomize();
    g.Show();
    snap->Restore();
    g.Show();
}



