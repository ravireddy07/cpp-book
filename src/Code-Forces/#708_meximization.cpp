//Problem Statement: https://codeforces.com/contest/1497/problem/A

/**
 *  Author: Ravi Kanth Gojur
 *  Code Forces: ravireddy07
 *  Code Chef: ravireddy115
 *  Github: ravireddy07
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int ar[n];
        for(int i=0;i<n;i++)
            scanf("%d", &ar[i]);
        sort(ar,ar+n);

        vector<int> v;
        printf("%d ", ar[0]);
        
        for(int i=1;i<n;++i){
            if(ar[i] != ar[i-1])
                printf("%d ", ar[i]);
            else
                v.push_back(ar[i]);
        }
        for(auto i : v)
            printf("%d ", i);
        printf("\n");
    }
    return 0;
}