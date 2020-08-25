#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

//  Solution with TLE

class Solution
{
public:
    vector<int> splitNum(int num, int n)
    {
        int digit;
        vector<int> res;
        while (num != 0)
        {
            digit = num % 10;
            num /= 10;
            res.push_back(digit);
        }
        reverse(begin(res), end(res));
        return res;
    }

    bool checkDiff(vector<int> ar, int n, int k)
    {
        bool status = true;
        int diff;
        for (int i = 0; i < n - 1; i++)
        {
            diff = abs(ar[i] - ar[i + 1]);
            if (diff != k)
            {
                status = false;
            }
        }
        return status;
    }

    vector<int> numsSameConsecDiff(int N, int K)
    {
        int start, end;
        vector<int> result;
        vector<int> cur_num;
        if (N == 1 or N == 0)
        {
            return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        }
        else if (N == 2)
        {
            start = 10;
            end = 99;
        }
        else if (N == 3)
        {
            start = 100;
            end = 999;
        }
        else if (N == 4)
        {
            start = 1000;
            end = 9999;
        }
        else if (N == 5)
        {
            start = 10000;
            end = 99999;
        }
        else if (N == 6)
        {
            start = 100000;
            end = 999999;
        }
        else if (N == 7)
        {
            start = 1000000;
            end = 9999999;
        }
        else if (N == 8)
        {
            start = 10000000;
            end = 99999999;
        }
        else if (N == 9)
        {
            start = 100000000;
            end = 999999999;
        }

        for (int i = start; i <= end; i++)
        {
            cur_num = splitNum(i, N);
            if (checkDiff(cur_num, N, K))
            {
                result.push_back(i);
            }
            while (!cur_num.empty())
            {
                cur_num.pop_back();
            }
        }
        return result;
    }
} a;

*/

// Solution

int mod(int a)
{
    return a >= 0 ? a : -1 * a;
}
class Solution
{
public:
    vector<int> v;
    void help(int n, int k, int s, int N, int prev)
    {
        //n-numDigits
        if (n == N)
        {
            v.push_back(s);
            return;
        }

        for (int i = 0; i <= 9; i++)
        {
            if (mod(prev - i) == k)
                help(n + 1, k, s * 10 + i, N, i);
        }
    }

    void fun(int k, int n)
    {
        for (int i = 1; i <= 9; i++)
        {
            help(1, k, i, n, i);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k)
    {
        if (n == 1)
        {
            for (int i = 0; i <= 9; i++)
                v.push_back(i);
            return v;
        }
        int s = 0;
        fun(k, n);
        return v;
    }
} a;

int main()
{
    vector<int> show;
    int N = 2, K = 3;
    show = a.numsSameConsecDiff(N, K);

    cout << "[";
    for (int i = 0; i < show.size(); i++)
    {
        if (i == show.size() - 1)
        {
            cout << show[i];
        }
        else
        {
            cout << show[i] << ", ";
        }
    }
    cout << "]";
    return 0;
}
