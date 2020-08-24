#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    string thousandSeparator(int n)
    {
        string s = to_string(n), res;
        for (int i = 0; i < s.size(); ++i)
        {
            if (i > 0 && (s.size() - i) % 3 == 0)
                res += ".";
            res += s[i];
        }
        return res;
    }
};

int main()
{
    Solution a;
    string result = a.thousandSeparator(9887);
    cout << result << endl;
}