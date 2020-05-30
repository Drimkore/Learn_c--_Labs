#pragma once
#include "MatrixBase.h"

class Matrix2D : public MatrixBase {
    private:
        static const int unsigned m_size = 2;
        int** matrix;

    public:
        Matrix2D():MatrixBase(m_size) {}
        ~Matrix2D() {};
};