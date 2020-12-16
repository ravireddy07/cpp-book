/*
Problem Statement:

A social network has n active users, numbered from 0 to n-1. Users selectively friend one another to create groups of friends 
within the network.
-- Two Users x and y are direct friends if they friend each other on the network.
-- Two Users x and z are indirect friends if there is some y common to both x and z.
-- Two Users x and y belong to the same group if they are friends directly or indirectly.
-- The number of people in each group is given as an array of n integers, counts where count[i] denotes the total number of users
in the group that the user belongs to.
-- All of the users in a particular group must have minimal id numbers.

Print the information of each vaild group in a new line as space separated integers in ASC order.
And groups themselves are ordered by smallest member ID in ASC order.

Sample Test Cases:


Sample: #1
Index:   0 1 2 3 4 5 6(this is not given in test case)
Count = {3,3,3,3,3,1,3}

Output:
Vaild Grouping(required answer)
0 1 2 : group 1
3 4 6 : group 2
5     : group 3

Invaild Grouping:
0 2 4 : group 1
2 3 6 : group 2
5     : group 3


Sample: #2
{2,2,2,2}

Output:
0 1
2 3

*/

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void test(vector<int> counts)
{
    vector<vector<int>> groups;
    map<int, pair<int, int>> m;

    for (int i = 0; i < counts.size(); ++i)
    {
        auto it = m.find(counts[i]);
        if (it == m.end())
        {
            if (counts[i] != 1)
                m[counts[i]] = {1, groups.size()};
            groups.push_back({i});
        }
        else
        {
            int groupCount = m[counts[i]].first;
            int groupNum = m[counts[i]].second;
            groups[groupNum].push_back(i);
            if (groupCount + 1 == counts[i])
                m.erase(counts[i]);
            else
                m[counts[i]] = {groupCount + 1, groupNum};
        }
    }

    sort(groups.begin(), groups.end());
    for (auto group : groups)
    {
        for (int person : group)
            printf("%d ", person);
        printf("\n");
    }
    return;
}

int main()
{
    test({3, 3, 3, 3, 3, 1, 3});
    return 0;
}
