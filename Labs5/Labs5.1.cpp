/*1. Напишите класс бинарного дерева поиска, котрый поддерждивает: вставка элементов по значению(Insert), поиск элементов по значению(Search)
    ТЗ:
    для класса TreeNode определить:
    - конструктор по умолчанию, инициализирующий значения элементов равных нулю, указатели дочерних узлов, равных nullptr;
    - конструктор, принимающий значение;
    - геттеры и сеттеры значения и дочерних узлов;
    - все поля класса должны быть private;
    для класса BinaryTree определить:
    - конструктор по умолчанию, инициализирующий значения элементов равных нулю, указатели дочерних узлов, равных nullptr;
    - конструктор, принимающий значение;
    - деструктор, удаляющий все узды дерева;
    - метод вставки Insert() (по значению);
    - метод поиска Search(), возвращающий указатель на узел (поиск по значению);
    - все поля класса должны быть private;
    - перегрузить (в private секции) методы поиска и вставки, данные методы должны принимать в качестве аргумента значение и указатель на узел
    (использовать данне перегрузки внутри метов Insert и Search, определенных в public секции).
*/


#include <iostream>

using namespace std;

template <typename T>
class  TreeNode
{
    private:
    int* value;
    TreeNode* leftNode;
    TreeNode* rightNode;
    TreeNode* parent;

    public:
    TreeNode(){
        leftNode = nullptr;
        rightNode = nullptr;
        parent = nullptr;
    }

    int getLeftNode(TreeNode *node){
        return *value;
    }

    void setLeftNode(int value, TreeNode *node){
        node->leftNode = value;
    }

    int getRightNode(TreeNode *node){
        return *value;
    }

    void setRightNode(int value, TreeNode *node){
        node->rightNode = value;
    }

    int getParent(TreeNode *node){
        return *value;
    }

    void setParent(int value, TreeNode *node){
        node->parent = value;
    }
};

template <typename T>
class BinaryTree{
    private:
    public:
    BinaryTree(){
        TreeNode *node;
    };
    ~BinaryTree();

    void Insert(int value){
        if (node == nullptr){
            node = new TreeNode();
            node->parent = value;
            node->leftNode = nullptr;
            node->rightNode = nullptr;
        }
        else{
            if (value < node->parent){
                node->leftNode = Insert(value, node->leftNode);
            }
            if (value > node->parent)
                node->rightNode = Insert(value, node->rightNode);
        }
    }

    int Search(int value){
        if (node>value){
            node = node->leftNode;
            Search(value);
        }
        if (node<value){
            node = node->rightNode;
            Search(value);
        }
        if (node == value){
            return *node;
        }
    }

    void treeprint() {
        if(node != nullptr) {
        treeprint(node->left);
        cout << node;
        treeprint(node->right);
        }
    }
};





template<typename T>
int main(){
    BinaryTree tree;
    tree.Insert(4);
    tree.Insert(2);
    tree.Insert(6);
    tree.Insert(8);
    tree.Insert(3);
    tree.treeprint();




    cout << "hello world";
    return 0;
}