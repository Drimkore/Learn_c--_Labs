/*2. Напишите алгоритм создания бинарного дерева поиска с минимальной высотой для отсортированного (по возрастанию) массива с уникльными целочисленными элементами.
    ТЗ:
    - использовать класс BinaryTree из предыдущего задания;
    - метод CreateMinimalBST() принимет указатель на начало массива, индекс начальног элемента, индекс конечного элемента.
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

    TreeNode* Search(int value, TreeNode *node) {
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
    BinaryTree* tree = new BinaryTree;
    tree->CreateMinimalBST(array, 0, 7);
    return 0;
}
