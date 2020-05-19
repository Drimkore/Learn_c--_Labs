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

template<typename T>
class  TreeNode
{
    private:
    T value;
    TreeNode* leftNode;
    TreeNode* rightNode;

    public:
    TreeNode() {
        value = T();
        leftNode = nullptr;
        rightNode = nullptr;
    }

    T getNodeValue() {
        return value;
    }

    TreeNode<T>* getLeftNode() {
        return leftNode;
    }

    TreeNode<T>* getRightNode() {
        return rightNode;
    }

    void setNodeValue(int num) {
        value = num;
    }

    T getLeftNodeValue() {
        return leftNode->value;
    }

    void setLeftNode(TreeNode<T>* node) {
        leftNode = node;
    }

    void setLeftNodeValue(T value) {
        leftNode->value = value;
    }

    T getRightNodeValue() {
        return rightNode->value;
    }

    void setRightNode(TreeNode<T>* node) {
        rightNode = node;
    }

    void setRightNodeValue(T value) {
        rightNode->value = value;
    }
};

template<typename T>
class BinaryTree{
    private:
    TreeNode<T>* root;
    BinaryTree* tree;

    void Insert(int value, TreeNode<T> *node) {
        if (node->getNodeValue() < value) {
            if (node->getRightNode() != nullptr) {
                Insert(value, node->getRightNode());
            }
            else {
                TreeNode<T>* newNode = new TreeNode<T>;
                node->setRightNode(newNode);
                node->setRightNodeValue(value);
            }
        }
        else if (node->getNodeValue() > value) {
            if (node->getLeftNode() != nullptr) {
                Insert(value, node->getLeftNode());
            }
            else {
                TreeNode<T>* newNode = new TreeNode<T>;
                node->setLeftNode(newNode);
                node->setLeftNodeValue(value);
            }
        }
    }

    TreeNode<T>* Search(int value, TreeNode<T> *node) {
        if (node != nullptr){
            if (node->getNodeValue() > value) {
                node = node->getLeftNode();
                Search(value, node);
            }
            else if (node->getNodeValue() < value) {
                node = node->getRightNode();
                Search(value, node);
            }
            else if (node->getNodeValue() == value) {
                return node;
            }
        }
        else {
            return nullptr;
        }
    }
    //метод выводил значения всех узлов дерева(использовался для проверки)
    /*void treeprint(TreeNode<T> *node) {
        if(node != nullptr) {
        treeprint(node->getLeftNode());
        cout << node->getNodeValue();
        treeprint(node->getRightNode());
        }
    }*/

    public:
    BinaryTree() {
        root = nullptr;
    };
    ~BinaryTree();

    void Insert(int value) {
        if (root != nullptr) {
            Insert(value, root);
        }
        else {
            TreeNode<T>* newNode = new TreeNode<T>;
            newNode->setNodeValue(value);
            root = newNode;
        }
    }

    TreeNode<T>* Search(int value) {
        return Search(value, root);
    }
    /*
    void treeprint() {
        treeprint(root);
    }*/
};

int main() {
    BinaryTree<int> *tree = new BinaryTree<int>;

    tree->Insert(1);
    tree->Insert(4);
    tree->Insert(2);
    tree->Insert(6);
    tree->Insert(8);
    tree->Insert(3);

    cout << endl << tree->Search(1) << endl;
    return 0;
}