// Problem Statement: https://codeforces.com/contest/1499/problem/C

/**
 *  Author: Ravi Kanth Gojur
 *  Code Forces: ravireddy07
 *  Code Chef: ravireddy115
 *  Github: ravireddy07
**/

#include <bits/stdc++.h>
#define ll long long int
#define yes printf("YES\n")
#define no printf("NO\n")
using namespace std;


const int max_n = 100111, inf = 1000111222;s
int t, n, a[max_n];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        long long ans = 1LL * inf * inf;
        vector<int> mn(2, inf);
        vector<int> cnt(2);
        vector<long long> sum(2);
        for (int i = 0; i < n; ++i) {
            mn[i % 2] = min(mn[i % 2], a[i]);
            sum[i % 2] += a[i];
            ++cnt[i % 2];
            if (i) {
                long long res = sum[0] + sum[1];
                res += 1LL * mn[0] * (n - cnt[0]);
                res += 1LL * mn[1] * (n - cnt[1]);
                ans = min(ans, res);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
