#include <iostream>
#include <vector>
#include "TreeNode.h"
#include <cassert>

using namespace std;

TreeNode::TreeNode() {}

TreeNode::~TreeNode() {}

bool TreeNode::isTerminal() {
    PlayField::FieldStatus fs = field.checkFieldStatus();
    return fs == PlayField::fsCrossesWin || fs == PlayField::fsNoughtsWin || fs == PlayField::fsDraw;
}

void TreeNode::addChild(TreeNode* child) {
    /*assert(this->childCount() < this->childQty());
	child->node = this;
    this->childNode.push_back(child);*/
}

TreeNode& TreeNode::operator[](int pos) const {

}

int TreeNode::childCount() {
    return childNode.size();
}

PlayField& TreeNode::value() const {
    return field;
}

int TreeNode::cildQty() const {
    if (this->node) {
        return this->node->childQty() - 1;
    }
    return PlayField::size * PlayField::size;
}
