// https://leetcode.com/problems/4sum/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n < 4)
            return ans;
        sort(begin(nums), end(nums));
        for (int i = 0; i < n - 3; i++)
        {
            if (i == 0 or nums[i] != nums[i - 1])
            {
                for (int j = i + 1; j < n - 2; j++)
                {
                    if (j == i + 1 or nums[j] != nums[j - 1])
                    {
                        int left = j + 1, right = n - 1;
                        while (left < right)
                        {
                            int sum = nums[i] + nums[j] + nums[left] + nums[right];
                            if (sum > target)
                                right--;
                            else if (sum < target)
                                left++;
                            else
                            {
                                ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                                while (left < right and nums[left] == nums[left + 1])
                                    left++;
                                while (left < right and nums[right] == nums[right - 1])
                                    right--;
                                left++;
                                right--;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution a;
    vector<int> input = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> show = a.fourSum(input, 0);
    cout << "[" << endl;
    for (int i = 0; i < show.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < 4; j++)
            if (j == 3)
            {
                cout << show[i][j];
            }
            else
            {
                cout << show[i][j] << ", ";
            }
        cout << "]" << endl;
    }
    cout << "]";
    return 0;
}