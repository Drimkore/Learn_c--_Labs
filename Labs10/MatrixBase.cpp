#pragma once
#include <iostream>
#include "MatrixBase.h"

using namespace std;

ostream& operator<<(ostream& stream, const MatrixBase& iMatrix) {
    for (int i = 0; i < iMatrix.m_size; i++) {
        for (int j = 0; j < iMatrix.m_size; j++) {
            stream << iMatrix.matrix[i][j] << " ";
        }
        stream << endl;
    }
    return stream;
}

void MatrixBase::operator*=(int iMult) {
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            matrix[i][j] *= iMult;
        }
    }
}

void MatrixBase::operator+=(MatrixBase &iAdd) {
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            matrix[i][j] += iAdd.element(i, j);
        }
    }
}

