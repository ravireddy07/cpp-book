// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Solution 1
class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        map<int, int> mp1;
        map<int, int> mp2;
        for (auto i : target)
            mp1[i]++;
        for (auto i : arr)
            mp2[i]++;
        return mp1 == mp2;
    }
};

// Solution 2
class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        return is_permutation(target.begin(), target.end(), arr.begin());
    }
};

// // Solution 3
class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        return unordered_multiset<int>(target.begin(), target.end()) == unordered_multiset<int>(arr.begin(), arr.end());
    }
};

int main()
{
    Solution a;
    vector<int> target = {1, 2, 3, 4}, arr = {2, 4, 1, 3};
    cout << a.canBeEqual(target, arr) << endl;
    return 0;
}