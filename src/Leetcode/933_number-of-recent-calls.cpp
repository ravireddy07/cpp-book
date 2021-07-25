// Problem Statement: https://leetcode.com/problems/number-of-recent-calls/

#include <bits/stdc++.h>
using namespace std;

class RecentCounter
{
public:
    vector<int> s;
    RecentCounter()
    {
    }

    int ping(int t)
    {
        s.push_back(t);
        vector<int>::iterator low = lower_bound(s.begin(), s.end(), t - 3000);
        return (s.end() - low);
    }
};

int main()
{
    RecentCounter *obj = new RecentCounter();
    cout << obj->ping(1) << "\n";
    cout << obj->ping(100) << "\n";
    cout << obj->ping(3001) << "\n";
    cout << obj->ping(3002) << "\n";
    return 0;
}
