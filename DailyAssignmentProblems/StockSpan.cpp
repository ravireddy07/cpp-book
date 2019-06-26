#include<bits/stdc++.h>
using namespace std;

void StockSpan(int a[], int n){
	stack<int> s;
	int ans[n]= {0};
	for(int day = 0 ; day < n ; day++){
		while( !s.empty() && a[s.top()] < a[day]){
			s.pop();
		}

		ans[day] = s.empty()?day+1:day-s.top();
		s.push(day);
	}
	for(int i=0;i<n;i++) {
		cout<<ans[i]<<" ";
	}
	cout<<"END"<<endl;
}

int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0 ; i< n; i++){
		cin >> a[i];
	}
  if(n>0){
		StockSpan(a,n);
	}
	return 0;
}
