#pragma once

#include <string>

using namespace std;

class Matrix
{
    private:
       int** M;
       int m, n;
    public:
       Matrix() {M = NULL;}
       string to_str();
};