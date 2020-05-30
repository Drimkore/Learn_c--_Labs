#include <iostream>
#include <vector>
#include "PlayField.h"

using namespace std;

class TreeNode{
    private:
        // Определяет возможное количество потомков на данном уровне дерева
        int childQty();
        TreeNode* node;
        const PlayField field;
        vector<TreeNode*> childNode;

    public:
        TreeNode();
        ~TreeNode();

        // Проверяет является ли вершина терминальной
        bool isTerminal();

        // Добавление нового потомка
        void addChild(TreeNode* node);

        // Возвращает ссылку на соответствующего потомка
        TreeNode& operator[](int num);

        // Возвращает текущее количество потомков у данной вершины
        int childCount();

        // Возвращает ссылку на состояние поля PlayField в данной вершине дерева
        PlayField& value() const;
};