#ifndef _MATRIX
    #include "rdarray.h"

    #define _MATRIX
#endif

namespace sudoku{
    //класс матрица
    class matrix{
        public:
        //функция проверки победы
        bool you_win();
        //функция записи значения в матрицу, где i, j - индексы, val - значение
        void write(int i, int j, int val);
        //функция создания нового игрового поля
        void new_puzzle();
        //функция решения матрицы solve() в init() в dfs(0,0)
        void solve();
        //функция сброса пользовательских изменений
        void reset();
        //функция считывания значений в сгенерированной матрице
        int read(int i, int j);
        int output(int (*mat)[10]);
        int input(int (*mat)[10]);
        matrix(int (*mat)[10]);
        matrix();

        private:
        //рабочая матрица
        int obj[10][10];
        int row[10];
        int col[10];
        int block[5][5];
        //матрица с "константами"
        int ne[10][10];
        sudoku::rdarray ra;
        //ф-ция составления игровой таблицы
        int dfs(int ni, int nj);
        //функция полного обнуления, в т.ч массивов
        void empty();
        //
        void init();
    };
}

//#ifndef MATRIX_H
//#define MATRIX_H

//#endif // MATRIX_H
