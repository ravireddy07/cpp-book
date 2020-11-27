// https://leetcode.com/problems/pancake-sorting/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> B;
    bool isSorted(vector<int> &A)
    {
        return A == B;
    }

    vector<int> pancakeSort(vector<int> &A)
    {
        B = A;
        sort(B.begin(), B.end());
        vector<int> res;
        int i = A.size() - 1, mx;
        while (!isSorted(A) && i > 0)
        {
            mx = max_element(A.begin(), A.begin() + i + 1) - A.begin();
            if (mx != i)
            {
                reverse(A.begin(), A.begin() + mx + 1);
                res.push_back(mx + 1);
                reverse(A.begin(), A.begin() + i + 1);
                res.push_back(i + 1);
            }
            i--;
        }
        return res;
    }
};

int main()
{
    Solution a;
    vector<int> input = {3, 2, 4, 1};
    vector<int> show = a.pancakeSort(input);

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