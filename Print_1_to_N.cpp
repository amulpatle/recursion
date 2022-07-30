#include <iostream>
using namespace std;
void PrintNum(int n)
{
    if (n == 0)
    {
        return;
    }
    PrintNum(n - 1);
    cout << n << " ";
}
int main()
{
    int n;
    cout << "Enter Number" << endl;
    cin >> n;
    PrintNum(n);
    return 0;
}