// Problem Statement: https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/

// Discussion thread: https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/discuss/944653/C%2B%2B-Simple-O(N)-Solution-or-Brute-Force-Solution-or-2-Solutions

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Best Solution
    string getSmallestString(int n, int k)
    {
        string res(n, 'a');
        k -= n;
        int midChar = 0;
        while (k > 0)
        {
            midChar = min(k, 25);
            k -= midChar;
            res[n - 1] += midChar;
            n--;
        }
        return res;
    }

    // Brute Force
    string getSmallestString(int n, int k)
    {
        char al[] = {'\n', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        string res = "";
        int mid = 0;
        do
        {
            if (k > 26)
            {
                if (k - 26 >= n - 1)
                {
                    res += al[26];
                    k -= 26;
                }
                else
                {
                    mid = k - n + 1;
                    res += al[mid];
                    k -= mid;
                }
            }
            else if (k != n)
            {
                mid = k - n + 1;
                res += al[mid];
                k -= mid;
            }
            else if (k == n)
            {
                res += al[1];
                k -= 1;
            }
            n--;
        } while (n > 0);
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution a;
    cout << a.getSmallestString(5, 73) << endl;
    return 0;
}
