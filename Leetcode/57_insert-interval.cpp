// https://leetcode.com/problems/insert-interval/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newinterval)
    {
        int flag = 1;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (newinterval[0] < intervals[i][0])
            {
                flag = 0;
                intervals.insert(intervals.begin() + i, newinterval);
                break;
            }
        }

        if (flag)
            intervals.insert(intervals.end(), newinterval);
        vector<vector<int>> ans;

        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= end)
                end = max(end, intervals[i][1]);
            else
            {
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> input1 = {{1, 3}, {6, 9}};
    vector<vector<int>> input2 = {2, 5};
    cout << a.insert(input1, input2) << endl;
    return 0;
}