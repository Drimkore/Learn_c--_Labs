#include <iostream>
#include <vector>
#include "PlayField.h"

using namespace std;

vector PlayField::getEmptyCells() const {
    vector<CellPos> emptyCell;
    return emptyCell;
}

PlayField PlayField::makeMove(CellPos cellPos) {
    return this + cellPos;
}

PlayField::FieldStatus PlayField::checkFieldStatus() const {
    FieldStatus status = fsNormal;
    return status;
}

PlayField::operator[](CellPos cellPos) {
    CellStatus status = csEmpty;
    return status;
}
