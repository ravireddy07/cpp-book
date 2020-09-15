// https://leetcode.com/problems/construct-the-rectangle/

#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        int sqr = sqrt(area), L, W, temp;
        for (int i = 1; i <= sqr; ++i)
        {
            if (area % i == 0)
            {
                temp = (area / i);
                if (W == i)
                    return {i, L};
                L = i;
                W = temp;
            }
        }
        return {W, L};
    }
};

int main()
{
    Solution a;
    vector<int> show = a.constructRectangle(4) << endl;
    cout << "[";
    for (int i = 0; i < show.size(); i++)
    {
        if (i == show.size() - 1)
            cout << show[i];
        else
            cout << show[i] << ", ";
    }
    cout << "]";
    return 0;
}