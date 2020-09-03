// https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/

#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int util(vector<int> &A, int val)
    {
        multiset<int> m;
        int start = 0;
        int res = 0;
        for (int i = 0; i < A.size(); i++)
        {
            m.insert(A[i]);
            while (m.size() and (*m.rbegin() > val))
                m.erase(m.find(A[start++]));
            res += (i - start + 1);
        }
        return res;
    }
    int numSubarrayBoundedMax(vector<int> &A, int L, int R)
    {
        return util(A, R) - util(A, L - 1);
    }
};

int main()
{
    vector<int> input = {2, 1, 4, 3};
    cout << Solution.numSubarrayBoundedMax(input, 2, 3) << endl;
    return 0;
}