#include <bits/stdc++.h>
#define ll long long int
#define oi(a) printf("%d\n", a)
#define oll(a) printf("%lld\n", a)
#define ii(a) scanf("%d", &a)
#define ill(a) scanf("%lld", &a)
#define f(i, x, y) for (int i = x; i < y; ++i)
using namespace std;

class cp
{
public:
    // Accepted Solution
    void test()
    {
        int a, b, c;
        ii(a);
        ii(b);
        ii(c);
        int p = (a + b + c) / 9;
        int q = (a + b + c) % 9;
        if (a >= p and b >= p and c >= p and q == 0)
            printf("YES\n");
        else
            printf("NO\n");
        return;
    }

    // Brute Force(TLE Solution)
    void test()
    {
        int a, b, c;
        ii(a);
        ii(b);
        ii(c);
        int shotNum = 1;
        while (1)
        {
            /*if (a > 6)
                a -= 6;
            else if (b > 6)
                b -= 6;
            else if (c > 6)
                c -= 6;
            else */
            if (shotNum == 7 and a <= 1 and b <= 1 and c <= 1)
            {
                printf("YES\n");
                break;
            }
            else if (a == 0 and b == 0 and c == 0)
            {
                printf("NO\n");
                break;
            }
            else if (shotNum == 7)
            {
                if (a > 0)
                    a--;
                if (b > 0)
                    b--;
                if (c > 0)
                    c--;
                shotNum = 1;
            }
            else if (shotNum <= 6)
            {
                if (a > 1)
                    a--;
                else if (b > 1)
                    b--;
                else if (c > 1)
                    c--;
                else
                {
                    printf("NO\n");
                    break;
                }
                shotNum++;
            }
            //cout << shotNum << " " << a << " " << b << " " << c << endl;
        }
        return;
    }
};

int main()
{
    cp a;
    int t;
    ii(t);
    while (t--)
        a.test();
    return 0;
}
