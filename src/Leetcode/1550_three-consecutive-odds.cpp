// https://leetcode.com/problems/three-consecutive-odds/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        int count = 0;
        for (int i = 0; i < arr.size(); ++i)
        {
            if (arr[i] % 2 != 0)
                count++;
            else
            {
                if (count >= 3)
                    return true;
                count = 0;
            }
        }
        if (count >= 3)
            return true;
        return false;
    }
};

int main()
{
    Solution a;
    vector<int> input = {1, 2, 34, 3, 4, 5, 7, 23, 12};
    cout << a.threeConsecutiveOdds(input) << endl;
    return 0;
}