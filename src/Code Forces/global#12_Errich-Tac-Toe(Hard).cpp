// Problem Statement: https://codeforces.com/contest/1450/problem/C2/

#include "bits/stdc++.h"
using namespace std;
using ll = long long int;
const int mod = 1e9 + 7;

// Method #1

const int N = 1e6 + 5;

int main()
{
    clock_t clk = clock();
    int t;
    cin >> t;
    while (t--)
    {
        int n, tok = 0;
        cin >> n;
        vector<string> arr(n);
        input(arr, n);
        int cnt[3][2] = {0};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == 'X')
                    cnt[(i + j) % 3][0]++, tok++;
                else if (arr[i][j] == 'O')
                    cnt[(i + j) % 3][1]++, tok++;
            }
        }
        int crs = -1, crc = -1;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == j)
                    continue;
                if (cnt[i][0] + cnt[j][1] <= floor((tok) / 3))
                {
                    crs = i;
                    crc = j;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int curr = (i + j) % 3;
                if (curr == crs && arr[i][j] == 'X')
                    arr[i][j] = 'O';
                else if (curr == crc && arr[i][j] == 'O')
                    arr[i][j] = 'X';
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
