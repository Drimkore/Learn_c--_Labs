/*4. Сравнить скороость выполнения поиска элемента в неотсортирвоанном и отсортированном массиве
    Результат вывести на экран
*/

#include <iostream>
#include <ctime>
#include "header.h"
#include <time.h>
#include <windows.h>

using namespace std;

int main() {
    cout.precision (9);
    int len = 1000;
    int *array = new int[len];
    srand(time(NULL));
    for (int i = 0; i<len; i++) {
        array[i] = rand() % 2001 -1000;
    }
    // Для неотсортированного
    long double beginFirts = clock();
    Search(len, 100, array);
    long double endFirst = clock();
    cout << "No Sort" << endl << (endFirst - beginFirts)/CLK_TCK << endl;

    recursionQuickSort(array, 0, len-1);
    // Для отсортированного
    long double beginSecond = clock();
    recursionBSearch(array, 0, len-1, 100);
    long double endSecond = clock();
    cout << "Sort" << endl << (endSecond - beginSecond)/CLK_TCK << endl;
    return 0;
}