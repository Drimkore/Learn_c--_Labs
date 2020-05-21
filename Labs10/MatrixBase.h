#include <iostream>

using namespace std;

ofstream& operator<<(ofstream& stream, const MatrixBase& iMatrix);

class MatrixBase {
    protected:
        MatrixBase(unsigned int iSize);

    private:
        const unsigned int m_size;
    public:
        unsigned const int size() {
            return m_size;
        }
        // Возвращает элемент матрицы
        int element(unsigned int i, unsigned int j) const;
        // Возвращает ссылку на элемент матрицы
        int& element(unsigned int i, unsigned int j);
        // Умножение всех элементов на iMult
        void operator*=(int iMult);
        // Сложение матрицы с матрицей iAdd
        void operator+=(MatrixBase iAdd);

};

ofstream& operator<<(ofstream& stream, const MatrixBase& iMatrix);

class Matrix2D : public MatrixBase {
    Matrix2D(iSize)

};

class Matrix3D : public MatrixBase {
    private:
        int*** array[3][3][3];
    public:

};

