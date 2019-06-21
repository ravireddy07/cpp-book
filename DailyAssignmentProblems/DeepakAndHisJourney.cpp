#include<iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  long long int T,N,Min,sum;
  cin>>T;
  while(T--) {
    cin>>N;
    
    int*C=new int[N];
    int*L=new int[N];

    for(int i=0;i<N;i++) {
      cin>>C[i];
    }

    for(int i=0;i<N;i++) {
      cin>>L[i];
    }

    Min=C[0];
    sum=0;

    for(int i=0;i<N;i++) {
      if(C[i] < Min){
        Min=C[i];
      }
    sum+=Min*L[i];
    }
    cout<<sum<<endl;
   }
   return 0;
}
