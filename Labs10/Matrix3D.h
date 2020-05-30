#pragma once
#include "MatrixBase.h"

class Matrix3D : public MatrixBase {
    private:
        static const int unsigned m_size = 3;
        int** matrix;

    public:
        Matrix3D():MatrixBase(m_size) {}
        ~Matrix3D() {};
};