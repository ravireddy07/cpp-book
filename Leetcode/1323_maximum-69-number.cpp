// https://leetcode.com/problems/maximum-69-number/

#include <iostream>
using namespace std;

class Solution
{
public:
    int maximum69Number(int num)
    {
        string res = to_string(num);
        for (int i = 0; i < res.length(); ++i)
            if (res[i] == '6')
            {
                res[i] = '9';
                break;
            }
        int a = stoi(res);
        return a;
    }
};

int main()
{
    Solution a;
    cout << a.maximum69Number(9669) << endl;
    return 0;
}