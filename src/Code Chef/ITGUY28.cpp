// Problem Statement: https://www.codechef.com/PBK32020/problems/ITGUY28

#include <bits/stdc++.h>
#define ll long long int
#define sheldon_harry printf("\n")
#define oi(a) printf("%d\n", a)
#define oll(a) printf("%lld\n", a)
#define ii(a) scanf("%d", &a)
#define ill(a) scanf("%lld", &a)
#define f (i, x, y) for (int i = x; i < y; ++i)
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define vll vector<vector<ll>>
#define yes printf("YES")
#define no printf("NO")
using namespace std;

/*
Input:
2
2
4


Output:
  2
 21
210
 21
  2
    4
   43
  432
 4321
43210
 4321
  432
   43
    4
*/

class cp
{
public:
    void test()
    {
        int n;
        ii(n);
        for (int i = n; i >= 0; --i)
        {
            for (int j = i; j >= 1; j--)
                cout << " ";
            for (int k = n; k >= i; k--)
                cout << k;
            cout << endl;
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = i; j >= 1; j--)
                cout << " ";
            for (int k = n; k >= i; k--)
                cout << k;
            cout << endl;
        }
        //sheldon_harry;
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

/*
Author: Ravi Kanth Gojur
Github: ravireddy07
*/
