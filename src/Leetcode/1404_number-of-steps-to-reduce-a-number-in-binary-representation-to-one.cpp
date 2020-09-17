// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/

#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSteps(string s)
    {
        int steps = 0, i = s.size() - 1;
        while (i > 0)
        {
            if (s[i] == '0')
                i--;
            else
            {
                int idx = i;
                while (idx >= 0)
                {
                    if (s[idx] == '0')
                        break;
                    s[idx] = '0';
                    idx--;
                }
                if (idx >= 0)
                    s[idx] = '1';
                else
                {
                    s.insert(s.begin(), 1, '1');
                    i++;
                }
            }
            steps++;
        }
        return steps;
    }
};

int main()
{
    Solution a;
    cout << a.numSteps("1101") << endl;
    return 0;
}