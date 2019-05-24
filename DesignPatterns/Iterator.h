#pragma once

#include<vector>



class Graph
{
    std::vector<std::vector<int>> m_graph;
public:
    class Iterator
    {
        const Graph* m_graph;
        int m_from, m_to;
    public:
        Iterator(const Graph* graph, int from, int to)
            : m_graph(graph)
            , m_from(from)
            , m_to(to)
        {

        }
        int GetNext()
        {
            m_to++;
            while (m_from != m_graph->size() && m_graph->Get(m_from).size() == m_to)
            {
                m_from++;
                m_to = 0;
            }
            if (!HasNext())
                return -1;
            return m_graph->Get(m_from)[m_to];
            
        }
        bool HasNext() const
        {
            return (m_from != m_graph->size());
        }
        bool operator==(const Iterator& it)
        {
            return (m_from == it.m_from && m_to == it.m_to);
        }
        bool operator!=(const Iterator& it)
        {
            return !(*this == it);
        }
        int operator*()
        {
            return m_graph->Get(m_from)[m_to];
        }
    };
public:
    Graph(const std::vector<std::vector<int>>& graph)
        : m_graph(graph)
    {}
    Iterator begin() const
    {
        return Iterator(this, 0, 0);
    }
    Iterator end() const
    {
        return Iterator(this, m_graph.size(), 0);
    }
    int size() const
    {
        return m_graph.size();
    }
    const std::vector<int>& Get(int i) const
    {
        return m_graph[i];
    }
};
#include<iostream>
void Test()
{
    std::vector<std::vector<int>> graph = 
    {
        {1, 2, 3},
        {2, 3},
        {0, 1, 4},
        {},
        {0}
    };
    // must print 123230140
    Graph g(graph);
    Graph::Iterator it = g.begin();
    while (it != g.end())
    {
        std::cout << *it;
        it.GetNext();
    }
}

