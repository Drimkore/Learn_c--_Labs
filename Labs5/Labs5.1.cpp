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

class  TreeNode
{
    private:
    int value;
    TreeNode* leftNode;
    TreeNode* rightNode;

    public:
    TreeNode() {
        value = int();
        leftNode = nullptr;
        rightNode = nullptr;
    }

    int getNodeValue() {
        return value;
    }

    TreeNode* getLeftNode() {
        return leftNode;
    }

    TreeNode* getRightNode() {
        return rightNode;
    }

    void setNodeValue(int num) {
        value = num;
    }

    int getLeftNodeValue() {
        return leftNode->value;
    }

    void setLeftNode(TreeNode* node) {
        leftNode = node;
    }

    void setLeftNodeValue(int value) {
        leftNode->value = value;
    }

    int getRightNodeValue() {
        return rightNode->value;
    }

    void setRightNode(TreeNode* node) {
        rightNode = node;
    }

    void setRightNodeValue(int value) {
        rightNode->value = value;
    }
};

class BinaryTree{
    private:
    TreeNode* root;
    BinaryTree* tree;

    void Insert(int value, TreeNode* node) {
        if (node->getNodeValue() < value) {
            if (node->getRightNode() != nullptr) {
                Insert(value, node->getRightNode());
            }
            else {
                TreeNode* newNode = new TreeNode;
                node->setRightNode(newNode);
                node->setRightNodeValue(value);
            }
        }
        else if (node->getNodeValue() > value) {
            if (node->getLeftNode() != nullptr) {
                Insert(value, node->getLeftNode());
            }
            else {
                TreeNode* newNode = new TreeNode;
                node->setLeftNode(newNode);
                node->setLeftNodeValue(value);
            }
        }
    }

    TreeNode* Search(int value, TreeNode* node) {
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
            TreeNode* newNode = new TreeNode;
            newNode->setNodeValue(value);
            root = newNode;
        }
    }

    TreeNode* Search(int value) {
        return Search(value, root);
    }
    /*
    void treeprint() {
        treeprint(root);
    }*/
};

int main() {
    BinaryTree* tree = new BinaryTree;

    tree->Insert(1);
    tree->Insert(4);
    tree->Insert(2);
    tree->Insert(6);
    tree->Insert(8);
    tree->Insert(3);

    cout << endl << "Узел со значением 1 имеет указатель: " << tree->Search(1) << endl;
    cout << endl << "Узел со значением 6 имеет указатель: " << tree->Search(6) << endl;
    return 0;
}