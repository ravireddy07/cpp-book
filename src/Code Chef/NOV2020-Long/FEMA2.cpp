
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        string s;
        scanf("%d%d", &n, &k);
        cin >> s;
        int p = k + 1, res = 0;
        queue<int> mag, iron;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'M')
                mag.push(i);
            if (s[i] == 'I')
                iron.push(i);
            if (s[i] == 'X' or i == n - 1)
            {
                int l, r, sheet;
                while (!mag.empty() and !iron.empty())
                {
                    sheet = 0;
                    l = min(mag.front(), iron.front());
                    r = max(mag.front(), iron.front());

                    for (int q = l; q <= r; q++)
                        if (s[q] == ':')
                            sheet++;

                    if ((p - abs(l - r) - sheet) > 0)
                    {
                        res++;
                        mag.pop();
                        iron.pop();
                    }
                    else if (mag.front() < iron.front())
                        mag.pop();
                    else
                        iron.pop();
                }

                while (!mag.empty())
                    mag.pop();
                while (!iron.empty())
                    iron.pop();
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
