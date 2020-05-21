/*
2. Напишите  код для удаления дубликатов из несортированного связного списка.
3. Реализуйте алгоритм для нахождения в односвязном списке k-го элемента с конца.*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

// Реализуем связный список
template<typename T>
class Node {
    public:
        T data;
        Node* next;
};

template<typename T>
class LinkedList {
    public:
        int len;
        Node<T>* head;

        LinkedList() {
            len = 0;
            head = nullptr;
        }
        ~LinkedList();

        //Добавление значения в список (в начало)
        void push(T data) {
            Node<T>* node = new Node<T>;
            node->data = data;
            node->next = head;
            head = node;
            len++;
        }

        //Добавление  значения в список (в конец)
        void push_back(T data){
            if (head == nullptr) {
                head = new Node<T>(data);
            }
            else {
                Node<T>* current = head;
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = new Node<T>(data);
            }
            len++;
        }

        //Удаление элемента с конца
        void pop() {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            len--;
        };

        int getLenght() {
            return len;
        }

        //Вывод элементов
        void print() {
            Node<T>* newHead = this->head;
            int i = 0;
            while(newHead) {
                cout << i << ": " << newHead->data << endl;
                newHead = newHead->next;
                i++;
            }
        }

        // Получение значения по индексу
        Node<T>* operator[](const int index) {
            Node<T>* head = this->head;
            int counter = 0;
            while (head != nullptr) {
                if (counter == index) {
                    return head;
                }
            head = head->next;
            counter++;
            }
        }

        //Удаление элемента из списка
        void removeAt(int index){
            if (index == 0){
                pop();
            }
            else{
                Node<T> *prev = this->head;
                for (int i = 0; i<index-1; i++)
                    prev = prev->next;
                Node<T> *toDel = prev->next;
                prev->next = toDel->next;
                delete toDel;
                len--;
            }
}
        // №2
        // Удаление дубликатов
        void duplicateDelete() {
            for (int i = 0; i < len; i++) {
                int count = 0;
                T pointNum = operator[](i)->data;
                for (int j = i; j < len; j++) {
                    T num = operator[](j)->data;
                    if (pointNum == num) {
                        count++;
                    }
                }
                if (count > 1) {
                    removeAt(i);
                    i--;
                }
            }
        }

        // №3
        //Поиск элемента с конца
        T searchBack(int index) {
            int i = len - index;
            if (i < 0) {
                cout << "Значение не найдено";
                return 0;
            }
            else {
                return operator[](i)->data;
            }
        }
};

int main() {
    LinkedList<int>* list = new LinkedList<int>;
    list->push(5);
    list->push(2);
    list->push(1);
    list->push(3);
    list->push(2);
    list->push(7);
    list->push(9);
    list->push(5);
    list->push(9);
    list->push(5);
    list->print();
    // 2
    cout << endl << "Удаляем дубликаты";
    list->duplicateDelete();
    cout << endl;
    list->print();
    // 3
    cout << "Второй элемент с конца: " << list->searchBack(2) << endl;
    cout << "Пятый элемент с конца: " << list->searchBack(5) << endl;
    return 0;
}



