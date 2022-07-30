#include <iostream>
using namespace std;
int sumdigit(int n)
{
    static int sum = 0;
    if (n == 0)
    {
        return 0;
    }
    return (n % 10) + sumdigit(n / 10);
}
int main()
{
    int n;
    cin >> n;
    cout << sumdigit(n);
    return 0;
}