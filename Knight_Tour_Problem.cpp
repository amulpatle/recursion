#include <bits/stdc++.h>
#define n 8
using namespace std;
int mat[n][n];

int row[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int col[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool issafe(int x, int y)
{
    if (x >= 0 && y >= 0 && mat[x][y] == -1 && x < n && y < n)
    {
        return true;
    }
    return false;
}

bool knight_tour(int x, int y, int move)
{
    if (move == n * n)
    {
        return true;
    }
    int x_move, y_move;
    for (int k = 0; k < n; k++)
    {
        x_move = x + row[k];
        y_move = y + col[k];
        if (issafe(x_move, y_move))
        {
            mat[x_move][y_move] = move + 1;
            if (knight_tour(x_move, y_move, move + 1) == 1)
                return true;
            else
                mat[x_move][y_move] = -1;
        }
    }
    return false;
}

int main()
{
    memset(mat, -1, sizeof(mat));
    mat[0][0] = 1;
    if (knight_tour(0, 0, 1))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << mat[i][j] << "  ";
            cout << endl;
        }
    }
    else
        cout << "Not possible\n";

    return 0;
}
