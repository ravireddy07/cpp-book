// Problem Statement: https://leetcode.com/problems/decoded-string-at-index/

/*
We decode the string and N keeps the length of decoded string, until N >= K.
Then we go back from the decoding position.
If it's S[i] = d is a digit, then N = N / d before repeat and K = K % N is what we want.
If it's S[i] = c is a character, we return c if K == 0 or K == N
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string decodeAtIndex(string S, int K)
    {
        long N = 0, i;
        for (i = 0; N < K; ++i)
            N = isdigit(S[i]) ? N * (S[i] - '0') : N + 1;
        while (i--)
            if (isdigit(S[i]))
                N /= S[i] - '0', K %= N;
            else if (K % N-- == 0)
                return string(1, S[i]);
        return "";
    }
};

// Brute Force(Unaccepted)
/*
class Solution
{
public:
    string decodeAtIndex(string s, int k)
    {
        string ans = "";
        for (int i = 0; i < s.size(); ++i)
        {
            if (ans.size() >= k)
                break;
            if (isalpha(s[i]))
                ans += s[i];
            else
            {
                long num = (long)(s[i] - 48) - 1;
                string temp = ans;
                for (int j = 0; j < num; ++j)
                    ans += temp;
            }
        }
        ans = ans[k - 1];
        return ans;
    }
};
*/

int main()
{
    Solution a;
    cout << a.decodeAtIndex("y959q969u3hb22odq595", 222280369) << endl;
    cout << a.decodeAtIndex("a2b3c4d5e6f7g8h9", 10) << endl;
    return 0;
}
