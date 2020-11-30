// Problem Statement: https://codeforces.com/contest/1455/problem/A

#include <bits/stdc++.h>
#define lli long long int
using namespace std;

lli f(lli x)
{
    string temp = to_string(x);
    reverse(temp.begin(), temp.end());
    string str = "";
    for (int i = 0; i < temp.length(); i++)
        if (temp[i] != '0')
            str += temp[i];
    return stoll(str);
}

void test()
{
    lli n;
    scanf("%lld", &n);
    set<lli> val;
    lli temp = 0;
    for (int i = 1; i <= n; i++)
    {
        temp = i / f(f(i));
        val.insert(temp);
    }
    cout << val.size() << endl;
    return;
}

// Accepted Solution
void test()
{
    string n;
    cin >> n;
    cout << n.size() << endl;
    return;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        test();
    return 0;
}
