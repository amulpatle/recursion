#include <iostream>
#include <vector>
using namespace std;
class solution
{
public:
    void find_comninations(vector<vector<int>> &ans, vector<int> ds, int left, int n, int k)
    {
        if (k == 0)
        {
            ans.push_back(ds);
            return;
        }
        for (int i = left; i <= n; ++i)
        {
            ds.push_back(i);
            find_comninations(ans, ds, i + 1, n, k - 1);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinations(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        int left = 1;
        find_comninations(ans, ds, left, n, k);
        return ans;
    }
};
using namespace std;
int main()
{
    solution s;
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<vector<int>> comb = s.combinations(n, k);
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