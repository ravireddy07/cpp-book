// https://leetcode.com/problems/largest-number/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> container;
        for (int i : nums)
            container.push_back(to_string(i));

        auto comp = [](string a, string b) {
            string f = a + b;
            string s = b + a;
            return f > s;
        };

        sort(begin(container), end(container), comp);
        string res = "";
        
        if (container.front() == "0")
            return "0";
        for (auto i : container)
            res = res + i;
        return res;
    }
};

int main()
{
    Solution a;
    vector<int> input = {3, 30, 34, 5, 9};
    cout << a.largestNumber(input) << endl;
    return 0;
}