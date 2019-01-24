#include "matrix.h"

void sudoku::matrix::init()
{
    for (int i = 0; i < 9; ++i)
    {
        this->row[i] = this->col[i] = 0;
        this->block[i/3][i%3] = 0;
    }
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if(this->obj[i][j])
            {
                int sig = (1 << (obj[i][j] - 1));
                this->row[i] |= sig;
                this->col[j] |= sig;
                this->block[i/3][j/3] |= sig;
                this->ne[i][j] = 1;
            }
            else this->ne[i][j] = 0;
        }
    }
}

int sudoku::matrix::input(int (*mat)[10])
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            this->obj[i][j] = mat[i][j];
        }
    }
    return 1;
}

sudoku::matrix::matrix(int (*mat)[10]):ra()
{
    input(mat);
}

sudoku::matrix::matrix()
{
    for (int i = 0; i < 9; ++i)
    {
        this->row[i] = this->col[i] = 0;
        this->block[i/3][i%3] = 0;
    }

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            this->obj[i][j] = 0;
        }
    }
}

int sudoku::matrix::dfs(int ni, int nj)
{
    if (this->obj[ni][nj])
    {
        if (nj+1 < 9)
            return dfs(ni, nj+1);
        else if (ni+1 < 9)
            return dfs(ni+1, 0);
        else
            return 1;
    }
    else
    {
        int sig = this->row[ni] | this->col[nj] | this->block[ni/3][nj/3];
        this->ra.narray();
        for (int i = 0; i < 9; ++i)
        {
            int ri = this->ra.read(i);
            int sign = (1<<(ri-1));
            if (!(sig & sign))
            {
                this->obj[ni][nj] = ri;
                this->row[ni] |= sign;
                this->col[nj] |= sign;
                this->block[ni/3][nj/3] |= sign;
                if (nj+1 < 9)
                {
                    if (dfs(ni, nj+1) > 0)
                        return 1;
                }
                else if (ni+1 < 9)
                {
                    if (dfs(ni+1, 0) > 0)
                        return 1;
                }
                else
                {
                    return 1;
                }
                this->obj[ni][nj] = 0;
                this->row[ni] ^= sign;
                this->col[nj] ^= sign;
                this->block[ni/3][nj/3] ^= sign;
            }
        }
        return -1;
    }
}

void sudoku::matrix::solve()
{
    init();
    dfs(0, 0);
}

int sudoku::matrix::output(int (*mat)[10])
{
    int res = 1;
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            mat[i][j] = this->obj[i][j];
            res = res && mat[i][j];
        }
    }
    return res;
}

void sudoku::matrix::write(int i, int j, int val)
{
    if (ne[i][j])
        return;
    this->obj[i][j] = val;
}

int sudoku::matrix::read(int i, int j)
{
    return this->obj[i][j];
}

void sudoku::matrix::empty()
{
    for (int i = 0; i < 9; ++i)
    {
        this->row[i] = this->col[i] = 0;
        this->block[i/3][i%3] = 0;
    }

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            this->obj[i][j] = 0;
        }
    }
}

//проверка выигрыша
bool sudoku::matrix::you_win()
{
    for (int i = 0; i < 9; ++i)
    {
        row[i] = 0;
        col[i] = 0;
        block[i/3][i%3] = 0;
    }
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            int sig = row[i] | col[j] | block[i/3][j/3];
            int sgn = (1 << (obj[i][j])); //(obj[i][j] -1)
            if (!(sig&sgn))
            {
                row[i] |= sgn;
                col[j] |= sgn;
                block[i/3][j/3] |= sgn;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

//новая игра
void sudoku::matrix::new_puzzle()
{
    empty();
    solve();
    srand(time(NULL));
    int rdbox = rand()%10 + 40;
    for (int k = 0; k < rdbox; ++k)
    {
        int i = rand()%9;
        int j = rand()%9;
        while(!obj[i][j])
        {
            i = rand()%9;
            j = rand()%9;
        }
        obj[i][j] = 0;
    }
    init();
}

//очистить всё
void sudoku::matrix::reset()
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (!ne[i][j])
                obj[i][j] = 0;
        }
    }
}
