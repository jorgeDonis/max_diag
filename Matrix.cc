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
    this->M = vector<vector<int>>(m, vector<int>(n));
}

Matrix::Matrix(unsigned int m, unsigned int n, bool init) : Matrix(m,n)
{
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
        sigma += M[i][i];
    return sigma;
}

void Matrix::permute(unsigned int j0, unsigned int j1)
{
    for (unsigned int i = 0; i < m; i++)
        swap(M[i][j0], M[i][j1]);
}

void Matrix::all_permutations(unsigned int k, vector<Matrix>& permutations)
{
    if (k == 1)
        permutations.push_back(*this);
    else
    {
        all_permutations(k - 1, permutations);
        for (unsigned int i = 0; i < k - 1; i++)
        {
            if (!(k % 2))
                permute(i, k - 1);
            else
                permute(0, k - 1);
            all_permutations(k - 1, permutations);
        }
    }
}

vector<Matrix> Matrix::all_permutations()
{
    Matrix ori_matrix(*this);
    vector<Matrix> foo = vector<Matrix>();
    all_permutations(n, foo);
    *this = ori_matrix;
    return foo;
}

Matrix::Matrix(const Matrix& B) : Matrix(B.m, B.n)
{
    for (unsigned int i = 0; i < B.m; i++)
    {
        for (unsigned int j = 0; j < B.n; j++)
            M[i][j] = B.M[i][j];
    }
}

Matrix& Matrix::operator=(const Matrix &B)
{
    if (&B != this)
    {
        m = B.m;
        n = B.n;
        this->M = vector<vector<int>>(m, vector<int>(n));
        for (unsigned int i = 0; i < B.m; i++)
        {
            for (unsigned int j = 0; j < B.n; j++)
                M[i][j] = B.M[i][j];
        }
    }
    return *this;
}
