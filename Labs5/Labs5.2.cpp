/*2. Напишите алгоритм создания бинарного дерева поиска с минимальной высотой для отсортированного (по возрастанию) массива с уникльными целочисленными элементами.
    ТЗ:
    - использовать класс BinaryTree из предыдущего задания;
    - метод CreateMinimalBST() принимет указатель на начало массива, индекс начальног элемента, индекс конечного элемента.
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

    void CreateMinimalBST(int* array, int firstIndex, int secondIndex) {
        int midIndex = (secondIndex + firstIndex)/2;
        Insert(array[midIndex]);
        if (midIndex < secondIndex){
            CreateMinimalBST(array, midIndex+1, secondIndex);
        }
        if (midIndex > firstIndex){
            CreateMinimalBST(array, firstIndex, midIndex-1);
        }
    }
};

main(){
    int array[8]  = {1,4,6,8,14,15,26,47};
    BinaryTree<int>* tree = new BinaryTree<int>;
    tree->CreateMinimalBST(array, 0, 7);
    return 0;
}
