#include <iostream>

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