#include <iostream>
#include <vector>

using namespace std;
class solution
{
public:
    void findcombination(int i, int n, vector<int> ds, vector<vector<int>> &ans)
    {
        if (n == 0)
        {
            ans.push_back(ds);
            return;
        }
        if (n > 0)
        {
            ds.push_back(i);

            findcombination(i, n - i, ds, ans);

            ds.pop_back();
        }
        if (i + 1 <= n)
        {
            findcombination(i + 1, n, ds, ans);
        }
    }

public:
    vector<vector<int>> combinationSum2(int n)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        int i = 1;
        findcombination(i, n, ds, ans);
        return ans;
    }
};

int main()
{

    solution s;
    int n;
    cin >> n;

    vector<vector<int>> comb = s.combinationSum2(n);
    for (int i = 0; i < comb.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < comb[i].size(); j++)
        {
            cout << comb[i][j] << " ";
        }
        cout << "]";
    }
    cout << " ]";

    return 0;
}
