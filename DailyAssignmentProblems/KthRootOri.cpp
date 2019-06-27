#include <bits/stdc++.h>
#define ff first
#define se second
#define pb push_back
#define nn 6000
#define mt make_tuple
#define mp make_pair
#define ll long long int
#define db double
#define ldb long double
#define inf 1000000000000000000ll
#define logn 20
#define mod 1000000007ll
#define mod1 mod
#define mod2 100000009ll
#define sqr(a) a*1ll*a
#define nullp mp(-1,-1)
#define set0(a) memset(a,0,sizeof a)
#define init(a) memset(a,-1,sizeof a)
#define cmp 1e-16

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int t;
    ll n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        if(k==1)
        {
            cout<<n<<endl;
            continue;
        }
        ll l=1,r=1000000,mid;
        while(l<r)
        {
            mid=l+r+1>>1;
            bool flag=1;
            ll tmp=1;
            for(int i=1;i<=k;i++)
            {
                tmp*=mid;
                if(tmp>n)
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
                l=mid;
            else
                r=mid-1;
        }
        cout<<r<<endl;
    }
    return 0;
}
