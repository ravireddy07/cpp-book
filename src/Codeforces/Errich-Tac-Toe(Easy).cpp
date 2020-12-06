// Problem Statement: https://codeforces.com/contest/1450/problem/C1/

#include "bits/stdc++.h"
using namespace std;
using ll = long long int;
const int mod = 1e9 + 7;

template <class T>
void mini(T &a, T b) { a = min(a, b); }

template <class T>
void maxi(T &a, T b)
{
    a = max(a, b);
}

// Method #1

int main()
{
    clock_t clk = clock();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> arr(n);
        input(arr, n);
        int cnt[3] = {0};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == 'X')
                    cnt[(i + j) % 3]++;
            }
        }
        int idx = min_element(cnt, cnt + 3) - cnt;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i + j) % 3 == idx && arr[i][j] == 'X')
                    arr[i][j] = 'O';
                cout << arr[i][j];
            }
            cout << "\n";
        }
    }
    //cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';
}

// Method #2
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ct[3] = {0, 0, 0};
        vector<string> v(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
            for (int j = 0; j < n; ++j)
                if (v[i][j] == 'X')
                    ++ct[(i + j) % 3];
        }
        int tot = ct[0] + ct[1] + ct[2];
        for (int i = 0; i < 3; ++i)
        {
            if (ct[i] > tot / 3)
                continue;
            for (int j = 0; j < n; ++j)
            {
                for (int k = 0; k < n; ++k)
                {
                    if ((j + k) % 3 != i)
                        continue;
                    if (v[j][k] == '.')
                        continue;
                    v[j][k] = 'O';
                }
                cout << v[j] << '\n';
            }
            break;
        }
    }
}
