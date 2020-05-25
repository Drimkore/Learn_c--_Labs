/*
 * Лабораторная работа №10
 *
 * Темы:
 *     классы (наследование, полиморфизм)
 *
 * ----------------------------------- Формулировка задания: -----------------------------------
    * Описать иерархию классов матриц произвольного размера со статическим выделением памяти под элементы.
 *
 * ------- Базовый класс матрицы MatrixBase -------
    * Для класса матрицы MatrixBase:
    *  - Конструктор по умолчанию удалить
    *  - Определить protected конструктор MatrixBase(unsigned int iSize), задающий размер матрицы
    *  - Определить приватное поле const unsigned int m_size, в котором хранится размерность матрицы
    *  - Метод unsigned int size() const возвращающий размерность матрицы
    *  - Абстрактный метод int element(unsigned int i, unsigned int j) const возвращающий элемент матрицы
    *  - Абстрактный метод int& element(unsigned int i, unsigned int j) возвращающий ссылку на элемент матрицы
    *  - перегрузить void operator*=(int iMult) умножения всех элементов матрицы на величину iMult
    *  - перегрузить void operator+=(MatrixBase iAdd) сложения матрицы с матрицей iAdd
    *  - перегрузить отдельно стоящий (не являющийся часть класса MatrixBase) оператор вывода
    *     содержимого матрицы в консоль std::ofstream& operator<<(std::ofstream& stream, const MatrixBase& iMatrix)
    *     объявление оператора разместить в заголовочном файле MatrixBase.h, определение -- в MatrixBase.cpp
    *
 * ------- Класс двухмерной матрицы Matrix2D -------
    * Определить класс двухмерной матрицы Matrix2D, являющийся public наследником класса MatrixBase.
    *
 * ------- Класс двухмерной матрицы Matrix3D -------
    * Определить класс трехмерной матрицы Matrix3D, являющийся public наследником класса MatrixBase.
    *
 * ------- Основная программа -------
    * Определить два экзмепляра Matrix2D и два экзмепляра Matrix3D.
    * Заполнить их упорядоченными значениями (1, 2, 3, ...)
    * Произвести с ними операции сложения и умножения, определёнными в соответствующих операторах класса MatrixBase.
    * Исходные данные и результаты вычислений вывести в консоль в человекочитаемом виде используя определённый по ТЗ
    * оператор вывода содержимого матрицы в виде такой конструкции: std::out << matrix << std::endl;
    *
*/
#include <iostream>
#include "MatrixBase.h"

using namespace std;

ofstream& operator<<(ofstream& stream, const MatrixBase& iMatrix) {
   for (int i = 0; i < iMatrix.m_size; i++) {
      for (int j = 0; j < iMatrix.m_size; j++) {
         stream << iMatrix.element(i, j);
      }
   }
   return stream;
}

void create(MatrixBase matrix, int size) {
   int num = 1;
   for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
         num++;
         matrix.element(i, j) = matrix.element(i, j);
      }
   }
}

void print(MatrixBase matrix, int size) {
   for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
         cout << matrix.element(i, j) << endl;
      }
   }
}

int main()
{
   Matrix2D m2a, m2b;
   Matrix3D m3a, m3b;


   //m2a->operator*=(2);
   //m2b->operator+=(m2a);



   cout << "HELLO?????";
   print(m2a, 4);

   cout << m2a << endl;
   cout << m2b << endl;

   cout << m3a << endl;
   cout << m3b << endl;

   return 0;
}
