
#include <iostream>
using namespace std;
void x(int n)
{

    for (int i = 0; i < n; i++)
    {

        cout << n << " ";
        x(n - 1);
    }
}
int main()
{
    int n;
    n = 3;
    x(n);
    return 0;
}