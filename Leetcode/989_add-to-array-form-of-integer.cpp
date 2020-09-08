// https://leetcode.com/problems/plus-one/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &A, int k)
    {
        vector<int> ans;
        int n = A.size(), i = n - 1, j = k, carry = 0;
        while (i >= 0 || j > 0)
        {
            int sum = (i >= 0 ? A[i] : 0) + (j > 0 ? j % 10 : 0) + carry;
            carry = (sum >= 10 ? 1 : 0);
            sum %= 10;
            ans.push_back(sum);
            i--;
            j /= 10;
        }
        if (carry == 1)
            ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution a;
    vector<int> input = {1, 2, 0, 0};
    vector<int> show = a.addToArrayForm(input, 34) << endl;
    cout << "[";
    for (int i = 0; i < show.size(); i++)
    {
        if (i == show.size() - 1)
        {
            cout << show[i];
        }
        else
        {
            cout << show[i] << ", ";
        }
    }
    cout << "]";
    return 0;
}