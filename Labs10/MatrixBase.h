#pragma once
#include <iostream>

using namespace std;

class MatrixBase {
    protected:
        MatrixBase() = delete;
        MatrixBase(unsigned int iSize):m_size(iSize) {
            matrix = new int* [iSize];
            for (int i = 0; i<iSize; i++) {
                matrix[i] = new int [m_size];
                for (int j = 0; j<iSize; j++) {
                    this->element(i, j) = 0;
                }
            }
        }

    private:
        const unsigned int m_size;
        int** matrix;

    public:
        // Возвращает размер матрицы
        unsigned const int size() {
            return m_size;
        }

        // Возвращает элемент матрицы
        virtual int element(unsigned int i, unsigned int j) const {
            return matrix[i][j];
        }

        // Возвращает ссылку на элемент матрицы
        virtual int& element(unsigned int i, unsigned int j) {
            return matrix[i][j];
        }

        // Умножение всех элементов на iMult
        void operator*=(int iMult);

        // Сложение матрицы с матрицей iAdd
        void operator+=(MatrixBase &iAdd);

        friend ostream& operator<<(ostream& stream, const MatrixBase& iMatrix);
};

ostream& operator<<(ostream& stream, const MatrixBase& iMatrix);




