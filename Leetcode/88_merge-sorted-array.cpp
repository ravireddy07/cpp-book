// https://leetcode.com/problems/merge-sorted-array/

#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int size = (m + n) - 1, i;
        for (i = size; i >= 0; i--)
        {
            if (m == 0 or nums2.size() == 0)
                break;
            if (nums2[nums2.size() - 1] > nums1[m - 1])
            {
                nums1[i] = nums2[nums2.size() - 1];
                nums2.pop_back();
            }
            else
            {
                nums1[i] = nums1[m - 1];
                --m;
            }
        }

        if (m != 0 and i >= 0)
        {
            for (int j = i; j >= 0; j--)
            {
                nums1[j] = nums1[m - 1];
                --m;
            }
        }
        else if (nums2.size() != 0 and i >= 0)
        {
            for (int j = i; j >= 0; j--)
            {
                nums1[j] = nums2[nums2.size() - 1];
                nums2.pop_back();
            }
        }
    }
};

int main()
{
    Solution a;
    vector<int> input1 = {1, 2, 3, 0, 0, 0}, input2 = {2, 5, 6};
    cout << a.merge(input1, input1.size(), input2, input2.size()) << endl;
    return 0;
}
