// https://leetcode.com/problems/reverse-string/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int n = s.size();
        int i = 0;
        int j = n - 1;
        while (i < j)
        {
            std::swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};

int main()
{
    Solution a;
    vector<char> input = {"h", "e", "l", "l", "o"};
    vector<char> show = a.reverseString(input);
    cout << "[";
    for (int i = 0; i < show.size(); ++i)
    {
        if (i == show.size() - 1)
            cout << show[i];
        else
            cout << show[i] << ", ";
    }
    cout << "]";
    return 0;
}