// https://leetcode.com/problems/count-and-say/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string next(string s)
    {
        string ans = "";
        int n = s.size(), i = 0, j = 0;
        while (i < n && j < n)
        {
            int count = 0;
            while (s[i] == s[j])
                ++j, ++count;
            ans += to_string(count);
            ans += s[i];
            i = j;
        }
        return ans;
    }
    string countAndSay(int n)
    {
        string s = "1";
        while (--n)
            s = next(s);
        return s;
    }
};

int main()
{
    Solution a;
    cout << a.countAndSay(4) << endl;
    return 0;
}