// Problem Statement: https://leetcode.com/problems/average-waiting-time/

// https://leetcode.com/problems/average-waiting-time/discuss/987475/C%2B%2B-Formula-Based-or-O(n)-Solution-or-Easy-or-worst-TimeSpace-or-LoL

#include <bits/stdc++.h>
using namespace std;

/*

for first dish,
    ans = prev_cust's (arrival time + cooking time) - curr_cust's arrival time.
ans = prev_cust's (arrival time + cooking time) - curr_cust's arrival time + waiting time of previous dish.

Test-Case:
[[5,2],[5,4],[10,3],[20,1]]

Arr.T     Cook.T   Total/Answer (prev_dishes_time + curr_dish_wait _time +  curr_dish_cook_time)
 5          2          2  
 5          4       (2+2+4)   5+2-5    = 2(current dish waiting time) 
 10         3       (8+1+3)   5+4-10+2(prev_dish_wait.t) = 1(current dish waiting time) 
 20         1       (12+0+1)  10+3-20+1 = -6 (no wait time, hence 0)
                    
                    13/4 = 3.25
 */

class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> customers)
    {
        int curTime = 0;
        double ans = customers[0][1];

        int check = 0, waitTime = 0;
        for (int i = 1; i < customers.size(); i++)
        {
            if (i == 1)
                waitTime = customers[i - 1][0] + customers[i - 1][1] - customers[i][0];
            else
                waitTime = customers[i - 1][0] + customers[i - 1][1] - customers[i][0] + waitTime;

            if (waitTime > 0)
                ans += waitTime;
            else
                waitTime = 0;       // If previous dish/customer had no waiting time
            ans += customers[i][1]; // Time Required to cook current customer's food
        }
        ans = ans / customers.size();
        return ans;
    }
};

int main()
{
    Solution a;
    cout << a.averageWaitingTime({{2, 3}, {6, 3}, {7, 5}, {11, 3}, {15, 2}, {18, 1}}) << "\n";
    cout << a.averageWaitingTime({{1, 2}, {2, 5}, {4, 3}}) << '|n';
    return 0;
}

/*
Author: Ravi Kanth Gojur
Github: ravireddy07
*/
