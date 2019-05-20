#pragma once

#include<vector>
#include<cstdlib>

struct Texture
{
    int img[1000000]; // Picture 1000x1000px
} texture;

// We have a tree, which is very "heavy" class
struct Tree
{
    int height;
    int width;
    Texture texture;
};

// Let's assume that we have forest in our new game, 
// and we want to store a lot of trees in it
// If we will store Trees it will take a lot of memory
// Need to store pointer in Tree, and create it in Flyweight
class Flyweight
{
    static std::vector<Tree*> m_all_trees;
public:
    static Tree* GetTree(int height, int width)
    {
        // Searching created tree
        for (int i = 0; i < m_all_trees.size(); ++i)
        {
            if (m_all_trees[i]->width == width &&
                m_all_trees[i]->height == height)
            {
                // if found - return it
                return m_all_trees[i];
            }
            // if not - create and return it
            m_all_trees.push_back(new Tree{ height, width, texture });
            return m_all_trees.back();
        }
    }
};
class Forest
{
    std::vector<Tree*> trees;
public:
    Forest()
    {
        for (int i = 0; i < 1000000; ++i)
        {
            // we will create at most 100 trees, and will take the needed
            // if it already created
            trees.push_back(Flyweight::GetTree(rand() % 10, rand() % 10));
        }
    }
};