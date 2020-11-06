// https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position

/*

We can move a chip at any position to 2 positions left or 2 positions right at no cost at all.
So we can keep moving all chips at positions of even numbers to position 2 at no cost, 
and all chips at odd positions to position 1 at no cost. Now, we have x chips at position 1 and y chips at position 2. 
If x > y, then move all y chips by 1 unit to the right to be at position 2, and return y. 
But if y > x, then move all x chips by 1 unit to the left to be at position 1, and return x.

Essentially, we're counting how many odd numbers and even numbers there are and returning the smaller count.
chips = [1,2,3]. 2 odd numbers and 1 even number. Return 1.
chips = [2,2,2,3,3]. 2 odd numbers and 3 even numbers. Return 2.
chips = [1,3,5,7,9,11,2,4]. 6 odd numbers and 2 even numbers. Return 2.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCostToMoveChips(vector<int> &position)
    {
        int odd = 0, even = 0;
        for (int i = 0; i < position.size(); i++)
        {
            if (position[i] % 2 == 0)
                even++;
            else
                odd++;
        }
        return min(odd, even);
    }
};

int main()
{
    Solution a;
    vector<int> in = {3, 3, 1, 2, 2};
    cout << a.minCostToMoveChips(in) << endl;
    return 0;
}
