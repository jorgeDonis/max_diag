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
    if (best_index != -1)
        return matrices[best_index];
    else
        return Matrix(3,3);
}

int main()
{
    Matrix m(5, 5, true);
    vector<Matrix> permutations = m.all_permutations();
    cout << "Smalles diag matrix  (calculated from all permutations): " << endl
     << smallest_diag(permutations).to_str() << endl;
    return 0;
}