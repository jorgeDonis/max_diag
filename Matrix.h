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
      Matrix(const Matrix&);
      ~Matrix() {;}
      Matrix& operator=(const Matrix& B);
      int diag_sum() const;
      void permute(unsigned int, unsigned int);
      void all_permutations(unsigned int, vector<Matrix>&);
      vector<Matrix> all_permutations();
      string to_str();
};