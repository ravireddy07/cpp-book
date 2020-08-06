7 1
2 1 3 1 1 4 5
5
1 1 2 1
1 2 3 1
1 4 5 1
2 2 2
1 1 2 3

#include <iostream>

using namespace std;

int main() {
	int n, x, q, qn, l, r, k, occr, index, value;
	cin>>n>>x;
	int ar[n];
	for(int i=0;i<n;i++) {
		cin>>ar[i];
	}
	cin>>q;
	for(int j=0;j<q;j++) {
		cin>>qn;
		if(qn == 1) {
			occr=0;
			cin>>l>>r>>k;
			for(int d=l;d<=r;d++) {
				if(ar[d] == x) {
					occr++;
					if(occr == k) {
						return d;
					}
				}
			}
			return -1;
		}
		else if(qn == 2) {
			cin>>index>>value;
			ar[index] = value;
		}
	}
    return 0;
}