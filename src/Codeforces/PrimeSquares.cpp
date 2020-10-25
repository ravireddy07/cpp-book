// https://codeforces.com/contest/1436/problem/B

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}

void test()
{
    int n;
    cin >> n;
    vector<int> res;
    int c = 1, k = 1, sum = 1, temp = 1;

    while (c != n)
    {
        if (k == 1)
            res.push_back(k);
        else if (!isPrime(k))
        {
            temp += k;
            if (isPrime(temp))
            {
                sum += k;
                res.push_back(k);
                c++;
            }
            temp = sum;
        }
        k++;
    }

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = i; j < res.size(); j++)
            cout << res[j] << " ";
        for (int j = i - 1; j >= 0; j--)
            cout << res[j] << " ";
        cout << endl;
    }
    return;
}

void test1()
{
    int n;
    cin >> n;
    vector<int> res(n);
    int rsum = 3;
    for (int i = 0; i < n; i++)
    {
        if (rsum > 0)
        {
            res[i] = 1;
            rsum--;
        }
        else
            res[i] = 0;
    }
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = i; j < res.size(); j++)
            cout << res[j] << " ";
        for (int j = i - 1; j >= 0; j--)
            cout << res[j] << " ";
        cout << endl;
    }
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        test();
    return 0;
}