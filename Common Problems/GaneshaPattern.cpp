#include<iostream>
using namespace std;
int main () {
  int n;
  cin>>n;
  cout<<"*";

  for(int i=1;i<=(n+1)/2 - 2;i++)
      cout<<" ";

  for(int i=1;i<=(n+1)/2;i++)
      cout<<"*";
  cout<<endl;

  for(int i=1;i<=(n+1)/2-2;i++) {
    cout<<"*";
    for(int j=1;j<=(n+1)/2-2;j++)
    cout<<" ";
    cout<<"*";
    cout<<endl;
    }

  for(int i=1;i<=n;i++)
      cout<<"*";
  cout<<endl;

  for(int i=1;i<=(n+1)/2-2;i++) {
    for(int j=1;j<=(n+1)/2-1;j++)
    cout<<" ";
    cout<<"*";
    for(int j=1;j<=(n+1)/2-2;j++)
    cout<<" ";
    cout<<"*";
    cout<<endl;
  }

  for(int i=1;i<=(n+1)/2;i++)
      cout<<"*";

  for(int i=1;i<=(n+1)/2-2;i++)
      cout<<" ";
  cout<<"*";

  return 0;
}
