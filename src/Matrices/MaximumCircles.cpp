/*
Prolem Statement: There are n circles arranged on x-y plane. All of them have their centers on x-axis. 
You have to remove some of them, such that no two circles are overlapping after that. 
Find the minimum number of circles that need to be removed.

Input:
4
1 1
2 1
3 1
4 1

Output:
2

*/

#include<iostream>
#include<algorithm>
using namespace std;

struct act{
    int beg; int end;
};

bool comp(act a,act b) {
    if(a.end==b.end) return a.beg<b.beg;
    return a.end<b.end;
}

int main() {
	int n;
	cin>>n;
	act arr[n];
	int c,r;
	 for(int i=0;i<n;++i) {
		 cin>>c>>r;
		 arr[i].beg=c-r;
		 arr[i].end=c+r;
	 }
	 sort(arr,arr+n,comp);
	 int curr=arr[0].end;
	 int done=1;
	 for(int i=1;i<n;++i) {
		 if(arr[i].beg>=curr) {
			 done++;
			 curr=arr[i].end;
			}
		}
		cout<<n-done<<endl;
		return 0;
}
