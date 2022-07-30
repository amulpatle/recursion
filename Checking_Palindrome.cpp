#include <iostream>
using namespace std;
int Palindrome(int n, int temp)
{

    if (n == 0)
    {
        return temp;
    }
    temp = (n % 10) + temp * 10;
    return Palindrome(n / 10, temp);
}
int main()
{
    int n;
    int temp;
    cout << "Enter Number" << endl;
    cin >> n;
    temp = Palindrome(n, 0);
    if (temp == n)
    {
        cout << "palindrome Number" << endl;
    }
    else
    {
        cout << " not palindrome Number " << endl;
    }

    return 0;
}