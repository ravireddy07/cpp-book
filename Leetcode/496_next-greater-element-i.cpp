// https://leetcode.com/problems/next-greater-element-i/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mp;
        stack<int> s;
        vector<int> result;
        int n1 = nums1.size(), n2 = nums2.size();

        for (int i = n2 - 1; i >= 0; i--)
        {
            if (s.empty())
                mp[nums2[i]] = -1;
            else if (!s.empty() && s.top() > nums2[i])
                mp[nums2[i]] = s.top();
            else if (!s.empty() && s.top() <= nums2[i])
            {
                while (!s.empty() && s.top() <= nums2[i])
                    s.pop();
                if (s.empty())
                    mp[nums2[i]] = -1;
                else
                    mp[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }
        for (int i = 0; i < n1; i++)
        {
            if (mp.count(nums1[i]))
                result.push_back(mp[nums1[i]]);
        }
        return result;
    }
};

int main()
{
    Solution a;
    vector<int> input1 = {4, 1, 2}, input2 = {1, 3, 4, 2};
    vector<int> shoow = a.findLHS(input1, input2);
    cout << "[";
    for (int i = 0; i < show.size(); i++)
    {
        if (i == show.size() - 1)
            cout << show[i];
        else
            cout << show[i] << ", ";
    }
    cout << "]";
    return 0;
}