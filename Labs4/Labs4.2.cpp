/*
2. Напишите  код для удаления дубликатов из несортированного связного списка.
3. Реализуйте алгоритм для нахождения в односвязном списке k-го элемента с конца.*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

// Реализуем связный список
template<typename T>
class LinkedList{
public:
    LinkedList();
    ~LinkedList();

    //Добавление значений в начало списка
    void push_front (T data);

    //Добавление значений в конец списка
    void push_back(T data);

    //Получение размера списка
    int getSize() {return Size;}

    //Возврат элемента списка
    T& operator[](const int index);

    //Удаление первого элемента
    void pop_front();

    //Удаление последнего элемента
    void pop_back();

    //Очистка всего списка
    void clear();

    //Вставка значений в список
    void insert(T data, int index);

    //Удаление элемента из списка
    void removeAt(int index);

    // 2
    void duplicateDelete();

private:
    template<typename Y>
    class Node{
        public:
        Node *pointNext;
        Y data;

        Node(Y date = Y(), Node *pointNext = nullptr){
            this->data = data;
            this->pointNext = pointNext;
        }

    };

    int Size;
    Node<T> *head;
};

template<typename T>
LinkedList<T>::LinkedList(){
    Size = 0;
    head = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList(){
}

template<typename T>
void LinkedList<T>::push_front(T data){
    head = new Node<T>(data, head);
    Size++;
}

template<typename T>
void LinkedList<T>::push_back(T data){
    if (head == nullptr){
        head = new Node<T>(data);
    }
    else{
        Node<T> *current = this->head;
        while (current->pointNext != nullptr){
            current = current->pointNext;
        }
        current->pointNext = new Node<T>(data);
    }
    Size++;
}

template<typename T>
T& LinkedList<T>::operator[](const int index){
    Node<T> *current = this->head;
    int counter = 0;
    while (current != nullptr){
        if (counter == index){
            return current ->data;
        }
        current = current->pointNext;
        counter++;
    }
}

template<typename T>
void LinkedList<T>::pop_front(){
    Node<T> *temp = head;
    head = head->pointNext;
    delete temp;
    Size--;
}

template<typename T>
void LinkedList<T>::pop_back(){
    removeAt(Size-1);
}

template<typename T>
void LinkedList<T>::clear(){
    while (Size != 0){
        pop_front();
    }
}

template<typename T>
void LinkedList<T>::insert(T data, int index){
    if (index == 0){
        push_front(data);
    }
    else{
        Node<T> *prev = this->head;

        for (int i = 0; i<index-1; i++)
            prev = prev->pointNext;
        Node<T> *newNode = new Node<T>(data, prev->pointNext);
        prev->pointNext = newNode;
        Size++;
    }
}

template<typename T>
void LinkedList<T>::removeAt(int index){
    if (index == 0){
        pop_front();
    }
    else{
        Node<T> *prev = this->head;
        for (int i = 0; i<index-1; i++)
            prev = prev->pointNext;
        Node<T> *toDel = prev->pointNext;
        prev->pointNext = toDel->pointNext;
        delete toDel;
        Size--;
    }
}

template<typename T>
void LinkedList<T>::duplicateDelete(){
    if (head == nullptr) return;

    Node<T> *current = this->head;
    int i = 0;
    //for (int i = 0; i < getSize(); i++){
	while (current != nullptr) {
		// Удаляем все следующие узлы с таким же значением
		Node<T> *runner = current;
		while (runner->pointNext != nullptr) {
			if (runner->pointNext->data == current->data) {
				removeAt(i);
                //runner->pointNext = runner->pointNext->pointNext;
			}
            else{
                runner = runner->pointNext;
			}
		}
		current = current->pointNext;
        i++;
	}
}

int main(){
    LinkedList<int> list;
    list.push_back(5);
    list.push_back(10);
    list.push_back(20);
    list.push_front(15);
    list.push_front(20);

    cout << list.getSize() << endl;

    for (int i = 0; i<list.getSize(); i++){
        cout << &list[i] << ' ';
    }
    cout << endl;
    //list.pop_front();
    list.duplicateDelete();
    cout << list.getSize() << &list.operator[](0) << endl;

    for (int i = 0; i<list.getSize(); i++){
        cout << &list[i] << ' ';
    }

    return 0;
}