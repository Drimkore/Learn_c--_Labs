#include <iostream>
#include <vector>

using namespace std;

class PlayField{
    public:

    class CellPos {
        private:
            int row;
            int column;
        public:
            CellPos();

            void setRow(int value) {
                row = value;
            };

            void setColumn(int value) {
                column = value;
            }

            int getRow() {
                return row;
            }

            int getColumn() {
                return column;
            }

    };

        static const int size = 3;

        enum FieldStatus {
            fsInvalid,        //- состояние поля некорректно (т.е. нельзя дойти до такого состояния соблюдая правила);
            fsNormal,         //- состояние поля корректно;
            fsCrossesWin,     //- победили крестики;
            fsNoughtsWin,     //- победили нолики;
            fsDraw            //- ничья.
        };

        const PlayField makeMove(CellPos cellPos) {};

        void operator[]() {};

        vector getEmptyCells() {};

        FieldStatus checkFieldStatus() {};

    private:
        void operator+(CellPos cellPos) {};



};