#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convertToTitle(int n)
    {
        string result;
        while (n)
            result.push_back('A' + (n - 1) % 26), n = (n - 1) / 26;
        reverse(result.begin(), result.end());
        return result;
    }
    /*
    string convertToTitle(int n)
    {
        return (n == 0) ? "" : convertToTitle((n - 1) / 26) + char(--n % 26 + 65);
    }
    */
};

int main()
{
    Solution a;
    cout << a.convertToTitle(800) << endl;
    return 0;
}