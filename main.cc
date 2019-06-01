#include "Matrix.h"
#include <iostream>
#include <limits>
#include <cmath>

Matrix smallest_diag(const vector<Matrix>& matrices)
{
    int smallest = numeric_limits<int>::max();
    int best_index = -1;
    int i = 0;
    for (Matrix m : matrices)
    {
        if (m.diag_sum() < smallest)
        {
            best_index = i;
            smallest = m.diag_sum();
        }
        i++;
    }
    if (!best_index)
        return matrices[i];
    else
        return Matrix(3,3);
}

int main()
{
    Matrix m(4, 4, true);
    vector<Matrix> permutations = m.all_permutations();
    for (Matrix matrix : permutations)
        cout << matrix.to_str() << endl;
    return 0;
}