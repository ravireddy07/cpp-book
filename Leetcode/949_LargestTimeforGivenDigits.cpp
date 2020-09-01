// https://leetcode.com/problems/largest-time-for-given-digits/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string largestTimeFromDigits(vector<int> &A)
    {
        string ans = "";
        string res = "";
        for (auto i : A)
        {
            res += to_string(i);
        }

        sort(res.begin(), res.end());
        do
        {
            string sub1 = res.substr(0, 2);
            string sub2 = res.substr(2);
            int f = stoi(sub1);
            int sec = stoi(sub2);
            if (f >= 0 && f <= 23 && sec >= 0 && sec <= 59)
            {
                ans = max(ans, sub1 + ":" + sub2);
            }

        } while (next_permutation(res.begin(), res.end()));
        return ans;
    }
};

int main()
{
    Solution a;
    vector<int> input = [ 1, 2, 3, 4 ];
    cout << a.largestTimeFromDigits(input) << endl;
    return 0;
}