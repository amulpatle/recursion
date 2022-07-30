#include <bits/stdc++.h>
using namespace std;

void permutations(string str, int s, int n)
{
    // base case
    if (s == n)
        cout << str << endl;
    else
    {
        for (int i = s; i <= n; i++)
        {
            swap(str[s], str[i]);
            permutations(str, s + 1, n);
            // Back track
            swap(str[s], str[i]);
        }
    }
}

int main()
{
    string str = "ABC";
    int n = str.size();
    permutations(str, 0, n - 1);

    return 0;
}