#include<iostream>
using namespace std;

long long int friends(long long int n){
	//Base Case
	if(n==0 or n==1) return 1;
    if(n==2) return 2;
     return friends(n-1) +((n-1)*friends(n-2));
}

int main(int argc, char const *argv[]){
    long long int n,t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        cout<<friends(n)<<endl;
    }
	return 0;
}
