#include "Matrix.h"
#include <experimental/random>
#include <iomanip>
#include <sstream>

#define MIN_INT 0
#define MAX_INT 50

Matrix::Matrix(unsigned int m, unsigned int n)
{
    this->m = m;
    this->n = n;
    M = vector<vector<int>>(m);
    for (unsigned int i = 0; i < m; i++)
       M[i] = vector<int>(n);
}

Matrix::Matrix(unsigned int m, unsigned int n, bool init)
{
    this->m = m;
    this->n = n;
    M = vector<vector<int>>(m);
    for (unsigned int i = 0; i < m; i++)
        M[i] = vector<int>(n);
    if (init)
    {
        for (unsigned int i = 0; i < m; i++)
            for (unsigned int j = 0; j < n; j++)
                M[i][j] = experimental::randint(MIN_INT, MAX_INT);
    }
}

string Matrix::to_str()
{
    stringstream ss;
    const char separator = ' ';
    const int width = 3;
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            ss << setw(width) << setfill(separator);
            ss << M[i][j];
        }
        if (i == m - 1)
                ss << "\t \t Diagonal sum = " << diag_sum();
        ss << "\n";
    }
    return ss.str();
}

int Matrix::diag_sum() const
{
    int sigma = 0;
    for (size_t i = 0; i < m; i++)
    {
        sigma += M[i][i];
    }
    return sigma;
}

void Matrix::permute(unsigned int j0, unsigned int j1)
{
    for (unsigned int i = 0; i < m; i++)
        swap(M[i][j1], M[i][j0]);
}

vector<Matrix> Matrix::all_permutations() const
{
    vector<Matrix> foo = vector<Matrix>();
}
