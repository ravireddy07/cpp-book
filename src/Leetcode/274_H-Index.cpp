// Problem Statement: https://leetcode.com/problems/h-index/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        //sort the array and scan the array
        int size = citations.size();
        if (size == 0)
            return 0;
        sort(citations.begin(), citations.end(), std::greater<int>());
        int i = 0;
        while (i < size && citations[i] >= i + 1)
            i++;
        return i;
    }
};

int main()
{
    Solution a;
    vector<int> input = {3, 0, 6, 1, 5};
    cout << a.hIndex(input) << "\n";
    return 0;
}
