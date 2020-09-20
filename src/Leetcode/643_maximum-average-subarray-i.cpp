// https://leetcode.com/problems/maximum-average-subarray-i/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        double sum = 0.0, j = 0, max_average = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (i >= k - 1)
            {
                double avg = sum / k;
                max_average = max(max_average, avg);
                sum -= nums[j];
                j++;
            }
        }
        return max_average;
    }
};

int main()
{
    Solution a;
    vector<int> input = {1, 12, -5, -6, 50, 3};
    cout << a.findMaxAverage(input, 4) << endl;
    return 0;
}