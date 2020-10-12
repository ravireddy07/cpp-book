// https://codeforces.com/contest/1427/problem/B

#include <bits/stdc++.h>
using namespace std;

/*
void test() {
    int n,k;
    cin >> n >> k;
    vector<char> in(n);
    int lc=0, wc = 0;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        if(in[i] == 'L')
            lc++;
        else if(in[i] == 'W')
            wc++;
    }

    if(lc <= k) {
        wc += lc;
        cout << (wc * 2) - 1 << endl;
        return;
    }
    
    for (int i = 0; i < n-2; i++) {
        if(in[i] == 'W' && in[i+1] == 'L' && in[i+2] == 'W' && k) {
            in[i + 1] = 'W';
            k--;
        }
        else if(in[i] == 'L' && in[i+1] == 'W' && in[i+2] == 'W' && k) {
            in[i] = 'W';
            k--;
        }
        else if(in[i] == 'L' && in[i+1] == 'L' && in[i+2] == 'W' && k) {
            in[i+1] = 'W';
            k--;
        }
        else if(in[i] == 'W' && in[i+1] == 'W' && in[i+2] == 'L' && k) {
            in[i+2] = 'W';
            k--;
        }
    }

    for (int i = 0; i < n-1; i++) {
        if(in[i] == 'W' && in[i+1] == 'L' && k) {
            in[i + 1] = 'W';
            k--;
        }
        else if(in[i] == 'L' && in[i+1] == 'W' && k) {
            in[i] = 'W';
            k--;
        }
        else if(in[i] == 'L' && in[i+1] == 'L' && k) {
            in[i+1] = 'W';
            k--;
        }
    }
    int res = 0, last=0;
    for (int i = 0; i < n; i++) {
        if(in[i] == 'W') {
            if(last == 1) {
                res += 1;
            }
            res += 1;
            last = 1;
        }
        else {
            last = 0;
        }
    }
    cout << res << endl;
    
    //for (int i = 0; i < n; i++)
        //cout << in[i] << " ";
    //cout << endl;
    
    return;
}
*/
char s[1000123];

void test()
{
    int n, k;
    cin >> n >> k;
    cin >> s;
    assert(n == (int)strlen(s));
    vector<int> blocks;
    for (int i = 0; i < n; i++)
    {
        bool start = (i > 0);
        if (s[i] == 'W')
            continue;
        int len = 1;
        while (i + 1 < n && s[i + 1] == 'L')
        {
            len++;
            i++;
        }
        if (start && i != n - 1)
            blocks.push_back(len);
    }
    sort(blocks.begin(), blocks.end());
    int ans = 0, remaining = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'W')
            ans++;
        else
            remaining++;

        if (s[i] == 'W' && i > 0 && s[i - 1] == 'W')
            ans++;
    }

    if (remaining == n && k > 0)
        ans--;

    for (int x : blocks)
    {
        if (k >= x)
        {
            k -= x;
            ans += 2 * x + 1;
            remaining -= x;
        }
        else
            break;
    }
    ans += 2 * min(k, remaining);
    cout << ans << endl;
}

int main()
{
    long t;
    cin >> t;
    while (t--)
        test();
    return 0;
}