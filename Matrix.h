#pragma once

#include <string>
#include <vector>


using namespace std;

class Matrix
{
    private:
       vector<vector<int>> M;
       unsigned int m, n;
    public:
       Matrix() {M = vector<vector<int>>();}
       Matrix(unsigned int, unsigned int);
       Matrix(unsigned int, unsigned int, bool);
       int diag_sum() const;
       void permute(unsigned int, unsigned int);
       vector<Matrix> all_permutations() const;
       string to_str();
};