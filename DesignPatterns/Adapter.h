#pragma once
#include<vector>
#include<cstdlib>

// We have class matrix, that stores only shorts
class Matrix
{
    std::vector<std::vector<short>> m_matrix;
public:
    // matrix content doesn't matter
    Matrix(int n = 10)
        : m_matrix(n, std::vector<short>(n))
    {
        for (auto& line : m_matrix)
            for (auto& elem : line)
                elem = rand();
    }
    const std::vector<std::vector<short>>& Get() const
    {
        return m_matrix;
    }
    // matrix other methods doesn't matter
};


// Now we have a third-party class that can 
// calculate number of zeros in vector<vector<int>>
// and want that given vector will be transposed
// so interface of our class is don't feet to this class
class ZeroCounter
{
    int number_of_zeros;
public:
    ZeroCounter(const std::vector<std::vector<int>>& matrix)
        : number_of_zeros(0)
    {
        for (auto& line : matrix)
            for (auto& elem : line)
                number_of_zeros += !elem;
    }
    int GetZeroCount() const
    {
        return number_of_zeros;
    }

};

// And we have a function that must take Matrix, 
// and return number of zeros in it
// Need to adapt our matrix's content to ZeroCounter class
int number_of_zeros_in_matrix(const Matrix& matrix);

// OK, let's create one Adapter class, that can convert one
// format to another

class MatrixToZeroCounterAdapter
{
    // take only a reference
    const Matrix& m_matrix;
public:
    MatrixToZeroCounterAdapter(const Matrix& matrix)
        : m_matrix(matrix)
    {

    }
    // Transposing and changing vector template type
    std::vector<std::vector<int>> Get() const
    {
        auto matrix = m_matrix.Get();
        std::vector<std::vector<int>>
                to_return(matrix[0].size(), std::vector<int>(matrix.size()));
        for (int i = 0; i < matrix.size(); ++i)
            for (int j = 0; j < matrix[0].size(); ++j)
                to_return[j][i] = matrix[i][j];
        return to_return;
    }
};

// Now we can implement this function this way
int number_of_zeros_in_matrix(const Matrix& matrix)
{
    return ZeroCounter(MatrixToZeroCounterAdapter(matrix).Get()).GetZeroCount();
}



