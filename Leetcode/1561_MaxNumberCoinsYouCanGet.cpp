#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxCoins(vector<int> &A)
    {
        sort(A.begin(), A.end());
        int res = 0, n = A.size();
        for (int i = n / 3; i < n; i += 2)
            res += A[i];
        return res;
    }
};

int main()
{
    Solution a;
    vector<int> input = {2, 4, 1, 2, 7, 8};
    int result = a.maxCoins(input);
    cout << result << endl;
    return 0;
}