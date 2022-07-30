#include <iostream>
#include <cmath>
using namespace std;
bool issafe(int mat[][9], int i, int j, int no, int n)
{
    for (int k = 0; k < n; k++)
    {
        if (mat[k][j] == no || mat[i][k] == no)
        {
            return false;
        }
    }
    int sx = (i / 3) * 3;
    int sy = (j / 3) * 3;
    for (int x = sx; x < sx + 3; x++)
    {
        for (int y = sy; y < sy + 3; y++)
        {
            if (mat[x][y] == no)
            {
                return false;
            }
        }
    }
    return true;
}

bool solversudoku(int mat[][9], int i, int j, int n)
{
    if (i == n)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }
    if (j == n)
    {
        return solversudoku(mat, i + 1, 0, n);
    }
    if (mat[i][j] != 0)
    {
        return solversudoku(mat, i, j + 1, n);
    }
    for (int no = 1; no <= n; no++)
    {
        if (issafe(mat, i, j, no, n))
        {
            mat[i][j] = no;
            bool solvesubprolem = solversudoku(mat, i, j + 1, n);
            {
                if (solvesubprolem == true)
                {
                    return true;
                }
            }
        }
    }
    mat[i][j] = 0;
    return false;
}
int main()
{
    int n = 9;
    int mat[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                     {5, 2, 0, 0, 0, 0, 0, 0, 0},
                     {0, 8, 7, 0, 0, 0, 0, 3, 1},
                     {0, 0, 3, 0, 1, 0, 0, 8, 0},
                     {9, 0, 0, 8, 6, 3, 0, 0, 5},
                     {0, 5, 0, 0, 9, 0, 6, 0, 0},
                     {1, 3, 0, 0, 0, 0, 2, 5, 0},
                     {0, 0, 0, 0, 0, 0, 0, 7, 4},
                     {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    if (!solversudoku(mat, 0, 0, n))
    {
        cout << "No solution exists";
    }

    return 0;
}