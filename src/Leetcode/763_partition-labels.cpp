// Problem Statement: https://leetcode.com/problems/partition-labels/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Greedy approach
    vector<int> partitionLabels(string s)
    {
        int n = s.size();
        vector<int> ans;

        if (n == 0)
            return ans;

        // find the last position of each letter in the string.
        vector<int> last_pos(26, -1);

        for (int i = n - 1; i >= 0; --i)
            if (last_pos[s[i] - 'a'] == -1)
                last_pos[s[i] - 'a'] = i;

        // minp is the min pos we need to consider in a partition.
        // plen is the length of the partition.
        int minp = -1, plen = 0;

        for (int i = 0; i < n; ++i)
        {
            int lp = last_pos[s[i] - 'a'];
            // Extend the current partition to consider this character's last pos.
            minp = max(minp, lp);
            // Increase the len of this partition.
            ++plen;

            // if the current pos of a character equals
            // the min pos we need to enclose in the current partition,
            // then we have reached the end of this partition.
            if (i == minp)
            {
                // store the partition's len and reset the variables.
                ans.push_back(plen);
                minp = -1;
                plen = 0;
            }
        }
        return ans;
    }
};

int main()
{
    Solution a;
    vector<int> show = a.partitionLabels("ababcbacadefegdehijhklij");
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
