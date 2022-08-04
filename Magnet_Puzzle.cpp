#include <iostream>
#include <string>
using namespace std;
#define n 6
#define m 5
int countinrow(char ans[][], int sign, int rowno)
{
    int counter = 0;
    for (int col = 0; col < ans[0].length; col++)
    {
        if (ans[rowno][col] == sign)
        {
            counter++;
        }
        return counter;
    }
}
int countincol(char ans[][], int sign, int colno)
{
    int counter = 0;
    for (int row = 0; row < ans[0].length; row++)
    {
        if (ans[row][colno] == sign)
        {
            counter++;
        }
        return counter;
    }
}

bool isItsafe(char ans[n][n], int top[], int left[], int right[], int bottom[], int row, int col, char sign)
{
    if ((col - 1 >= 0 && ans[row][col - 1] == sign) || (row - 1 >= 0 && ans[row - 1][col] == sign) || (col + 1 < ans.length() && ans[row][col + 1] == sign))
    {
        return false;
    }
    if (sing == '+')
    {
        int cinr = countinrow(ans, left, sign, row);
        int cinc = countincol(ans, top, sing, col);

        if (left[row] ! = -1 && cinr > left[row])
        {
            return false;
        }
        if (top[col] != -1 && cinc > top[col])
        {
            return false;
        }
    }
    else
    {
        int cinr = countinrow(ans, right, sign, row);
        int cinc = countincol(ans, bottom, sing, col);

        if (left[row] != -1 && cinr > right[row])
        {
            return false;
        }
        if (top[col] != -1 && cinc > bottom[col])
        {
            return false;
        }
    }
    return true;
}
bool isansvalid(char ans[][], int top[], int left[], int right[], int bottom[])
{
    for (int i = 0; i < top.lenght; i++)
    {
        int cinc = countincol(ans, top, '+', i);
        if (top[i] != -1 && top[i] != cinc)
        {
            return false;
        }
    }
    for (int i = 0; i < top.lenght; i++)
    {
        int cinc = countinrow(ans, top, '+', i);
        if (left[i] != -1 && top[i] != cinr)
        {
            return false;
        }
    }
    for (int i = 0; i < bottom.lenght; i++)
    {
        int cinc = countincol(ans, bottom, '-', i);
        if (bottom[i] != -1 && bottom[i] != cinc)
        {
            return false;
        }
    }
    for (int i = 0; i < right.lenght; i++)
    {
        int cinc = countinrow(ans, right, '-', i);
        if (right[i] != -1 && right[i] != cinr)
        {
            return false;
        }
    }
    return true;
}
bool solution(char arr[n][n], int top[], int left[], int right[], int bottom[], char ans[n][m], int row, int col)
{
    if (col == arr.leght())
    {
        col = 0;
        row++;
    }

    if (row == arr.length())
    {
        if (isansvalid(ans, top, left, bottom, ans) == true))
            {
                return true;
            }
        return false;
    }

    if (arr[row][col] == 'L')
    {
        if (isItsafe(arr, top, left, right, bottom, row, col, '+') && isItsafe(arr, left, right, bottom, row, col + 1, '-'))
        {
            ans[row][col] = '+';
            ans[row][col + 1] = '-';
            if (solution(arr, top, left, right, bottom, ans, row, col + 1) == true)
            {
                return true;
            }
            ans[row][col] = 'X';
            ans[row][col + 1] = 'X';
        }
        if (isItsafe(arr, top, left, right, bottom, row, col, '-') && isItsafe(arr, left, right, bottom, row, col + 1, '+'))
        {
            ans[row][col] = '-';
            ans[row][col + 1] = '+';
            if (solution(arr, top, left, right, bottom, ans, row, col + 1) == true)
            {
                return true;
            }
            ans[row][col] = 'X';
            ans[row + 1][col] = 'X';
        }
    }
    else if (arr[row][col] == 'T')
    {
        if (isItsafe(arr, top, left, right, bottom, row, col, '+') && isItsafe(arr, left, right, bottom, row + 1, col, '-'))
        {
            ans[row][col] = '+';
            ans[row + 1][col] = '-';
            if (solution(arr, top, left, right, bottom, ans, row, col + 1) == true)
            {
                return true;
            }
            ans[row][col] = 'X';
            ans[row + 1][col + 1] = 'X';
        }
        if (isItsafe(arr, top, left, right, bottom, row, col, '-') && isItsafe(arr, left, right, bottom, row + 1, col, '+'))
        {
            ans[row][col] = '-';
            ans[row + 1][col] = '+';
            if (solution(arr, top, left, right, bottom, ans, row, col + 1) == true)
            {
                return true;
            }
            ans[row][col] = 'X';
            ans[row][col + 1] = 'X';
        }
    }
    bool f2 = solution(arr, top, left, right, bottom, ans, row, col + 1)
    {
        if (f2 == true)
        {
            return true;
        }
        return false;
    }
}

int main()
{

    return 0;
}