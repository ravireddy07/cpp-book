// https://leetcode.com/problems/valid-permutations-for-di-sequence/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int numPermsDISequence(string S)
    {
        int n = S.length(), mod = 1e9 + 7;
        vector<vector<int>> res(n + 1, vector<int>(n + 1));
        for (int j = 0; j <= n; j++)
            res[0][j] = 1;
        for (int i = 0; i < n; i++)
        {
            if (S[i] == 'I')
            {
                for (int j = 0, cur = 0; j < n - i; j++)
                    res[i + 1][j] = cur = (cur + res[i][j]) % mod;
            }
            else
            {
                for (int j = n - i - 1, cur = 0; j >= 0; j--)
                    res[i + 1][j] = cur = (cur + res[i][j + 1]) % mod;
            }
        }
        return res[n][0];
    }
};

int main()
{
    Solution a;
    cout << a.numPermsDISequence("DID") << endl;
    return 0;
}