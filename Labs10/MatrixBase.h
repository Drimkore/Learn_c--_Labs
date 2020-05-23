#include <iostream>

using namespace std;

class MatrixBase {
    protected:
        MatrixBase() = delete;
        MatrixBase(unsigned int iSize);

    private:
        const unsigned int m_size;
        int** matrix;

    public:
        unsigned const int size() {
            return m_size;
        }

        // Возвращает элемент матрицы
        virtual int element(unsigned int i, unsigned int j) const = 0;

        // Возвращает ссылку на элемент матрицы
        virtual int& elementLink(unsigned int i, unsigned int j) const = 0;

        // Умножение всех элементов на iMult
        void operator*=(int iMult) {
            for (int i = 0; i < m_size; i++) {
                for (int j = 0; j < m_size; j++) {
                    matrix[i][j] *= iMult;
                }
            }
        };

        // Сложение матрицы с матрицей iAdd
        void operator+=(MatrixBase* iAdd) {
            for (int i = 0; i < m_size; i++) {
                for (int j = 0; j < m_size; j++) {
                    /*this->elementLink(i, j)*/ matrix[i][j] += iAdd->element(i, j);
                }
            }
        };
};

ostream& operator<<(ostream& stream, const MatrixBase& iMatrix);

class Matrix2D : public MatrixBase {
    private:
        const unsigned int m_size = 2;
        int** matrix;

    public:
        Matrix2D():MatrixBase(m_size) {
            int num = 1;
            for (int i = 0; i<m_size; i++) {
                for (int j = 0; j<m_size; j++) {
                    matrix[i][j] = num;
                    num++;
                }
            }
        }
        ~Matrix2D();

        virtual int element(unsigned int i, unsigned int j) const override {
            return matrix[i][j];
        }

        virtual int& elementLink(unsigned int i, unsigned int j) const override {
            return matrix[i][j];
        }
};

class Matrix3D : public MatrixBase {
    private:
        const unsigned int m_size = 3;
        int** matrix;

    public:
        //Matrix3D():MatrixBase(3) {};
        Matrix3D():MatrixBase(m_size) {
            int num = 1;
            for (int i = 0; i<m_size; i++) {
                for (int j = 0; j<m_size; j++) {
                    matrix[i][j] = num;
                    num++;
                }
            }
        }
        ~Matrix3D();

        virtual int element(unsigned int i, unsigned int j) const override {
            return matrix[i][j];
        }

        virtual int& elementLink(unsigned int i, unsigned int j) const override {
            return matrix[i][j];
        }
};
