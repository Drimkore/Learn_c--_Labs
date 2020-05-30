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
            }

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

        enum CellStatus {
            csEmpty,        // - ячейка пуста;
            csCross,        // - в ячейке крестик;
            csNought        // - в ячейке нолик;
        };

        enum FieldStatus {
            fsInvalid,        //- состояние поля некорректно (т.е. нельзя дойти до такого состояния соблюдая правила);
            fsNormal,         //- состояние поля корректно;
            fsCrossesWin,     //- победили крестики;
            fsNoughtsWin,     //- победили нолики;
            fsDraw            //- ничья.
        };
        // Возврат нового поля со сделанным в данной клетке ходом
        const PlayField makeMove(CellPos cellPos) {};
        // оператор[] для чтения ячеек, возвращающий перечислитель
        CellStatus operator[](CellPos cellPos) {};
        // метод возврата всех пустых позиций клеток
        vector getEmptyCells();
        // Метод проверки состояния поля
        FieldStatus checkFieldStatus();

    private:
        // оператор+ постановки очередной пометки (крестика или нолика)
        void operator+(CellPos cellPos) {};
};