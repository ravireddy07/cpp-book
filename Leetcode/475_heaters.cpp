// https://leetcode.com/problems/heaters/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int j = 0;
        int res = 0;
        for (int i = 0; i < heaters.size() - 1; i++)
        {
            int dis = heaters[i] + (heaters[i + 1] - heaters[i]) / 2;
            while (j < houses.size() && houses[j] <= dis)
            {
                res = max(res, abs(houses[j] - heaters[i]));
                j++;
            }
        }
        if (j == houses.size())
            return res;
        res = max(res, max(houses.back() - heaters.back(), heaters.back() - houses[j]));
        return res;
    }
};

int main()
{
    Solution a;
    vector<int> input1 = {1, 2, 3, 4};
    vector<int> input2 = {1, 4};
    cout << a.findRadius(input1, input2) << endl;
    return 0;
}