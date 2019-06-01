#include "Matrix.h"
#include <iostream>


int main()
{
    Matrix m(4, 4, true);
    cout << m.to_str() << endl;
    m.permute(0, 1);
    cout << m.to_str() << endl;
    return 0;
}