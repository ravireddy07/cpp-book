// https://leetcode.com/problems/decompress-run-length-encoded-list/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> decompressRLElist(vector<int> &nums)
    {
        vector<int> res;
        for (int i = 0; i < nums.size(); i += 2)
            for (int j = nums[i]; j > 0; j--)
                res.push_back(nums[i + 1]);
        return res;
    }
};

int main()
{
    Solution a;
    vector<int> input = {1, 2, 3, 4};
    vector<int> show = a.decompressRLElist(input);
    cout << "[";
    for (int i = 0; i < show.size(); i++)
    {
        if (i == show.size() - 1)
            cout << show[i];
        else
            cout << show[i] << ", ";
    }
    cout << "]" << endl;
    return 0;
}