// https://leetcode.com/problems/odd-even-jump/

#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int oddEvenJumps(vector<int>& A) {
        int n=A.size();
        vector<int> odd(n),even(n);
        odd[n-1]=even[n-1]=true;
        set<pair<int,int> > s;
        set<pair<int,int> >s2;
        s.insert(make_pair(A[n-1],n-1));
        s2.insert(make_pair(A[n-1]*(-1),n-1));
        set<pair<int,int> >::iterator itr;
        int ans=1;
        for(int i=n-2;i>=0;--i)
        {
            if((itr=s.lower_bound({A[i],i}))==s.end()){
                odd[i]=false;
            }
            else{
                odd[i]=even[itr->second];
            }
            if((itr=s2.lower_bound({-1*A[i],i}))==s2.end()){
                even[i]=false;
            }
            else{
                even[i]=odd[itr->second];
            }
            if(odd[i])
                ++ans;
            s.insert({A[i],i});
            s2.insert({(-1)*A[i],i});
        }
    return ans;
    }
};

int main()
{
    vector<int> input = {10,13,12,14,15};
    Solution a;
    cout << a.oddEvenJumps(input)<<endl;
    return 0;
}