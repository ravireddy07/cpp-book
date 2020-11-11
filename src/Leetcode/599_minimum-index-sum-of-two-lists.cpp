// https://leetcode.com/problems/minimum-index-sum-of-two-lists
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        vector<string> res;
        int min = INT_MAX;
        for (int i = 0; i < list1.size(); ++i)
        {
            for (int j = 0; j < list2.size(); ++j)
            {
                if (list1[i] == list2[j] && (i + j) <= min)
                {
                    res.push_back(list1[i]);
                    min = i + j;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution a;
    vector<string> input1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"},
                   input2 = {"KFC", "Shogun", "Burger King"};
    vector<string> show = a.findRestaurant(input1, input2);
    cout << "[";
    for (int i = 0; i < show.size(); i++)
    {
        if (i == show.size() - 1)
            cout << show[i];
        else
            cout << show[i] << ", ";
    }
    cout << "]" << endl;
    return 0;
}
