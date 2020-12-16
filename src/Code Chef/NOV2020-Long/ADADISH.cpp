// https://www.codechef.com/NOV20B/problems/ADADISH

#include <bits/stdc++.h>
using namespace std;

int findMinR(vector<int> v, int i, int currSum, int res)
{
    if (i == 0)
        return abs((res - currSum) - currSum);
    return min(findMinR(v, i - 1, currSum + v[i - 1], res), findMinR(v, i - 1, currSum, res));
}
// 2 3 4 5
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        vector<int> v(n);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &v[i]);
            sum += v[i];
        }
        sort(v.begin(), v.end());

        if (n == 1)
            printf("%d\n", v[0]);
        else if (n == 2)
            printf("%d\n", v[1]);
        else
        {
            int div2 = findMinR(v, n, 0, sum);
            double res = ((sum / 2) - div2 / 2) + div2;
            printf("%d\n", (int)res);
        }
    }
    return 0;
}
