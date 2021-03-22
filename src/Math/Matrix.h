#pragma once
#include "../common.h"
class Matrix{
    public:
        Matrix(const int rows, const int cols);
    
    private:
        double* m_data;

};