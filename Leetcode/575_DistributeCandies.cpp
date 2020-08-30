//  https://leetcode.com/problems/distribute-candies/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int distributeCandies(vector<int> &candies)
    {
        int n = candies.size();
        set<int> s;
        for (int i = 0; i < candies.size(); i++)
        {
            s.insert(candies[i]);
            if (s.size() == (n / 2))
            {
                return (n / 2);
            }
        }
        return s.size();
    }
};

int main()
{
    vector<int> input = {1, 1, 2, 2, 3, 3};
    Solution a;
    cout << a.distributeCandies(input) << endl;
    return 0;
}