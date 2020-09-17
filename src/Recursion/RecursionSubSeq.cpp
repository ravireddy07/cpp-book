#include<iostream>
#include<cstring>
using namespace std;

#define ll long long int
void SubSeq(string str,string osf) {
	if(str.length()==0) {
		cout<<osf<<" ";
		return;
  }
	char ch=str[0];
	string ros=str.substr(1);
	SubSeq(ros,osf);
  SubSeq(ros,osf+ch);
}

ll RecrSubSeq(string str,string osf) {
	if(str.length()==0) {
		return 1;
  }
	char ch=str[0];
	string ros=str.substr(1);
	long long int result=0;
	result+=RecrSubSeq(ros,osf);
	result+=RecrSubSeq(ros,osf+ch);
	return result;
}

int main() {
	string str;
	cin>>str;
	SubSeq(str," ");
	cout<<endl;
	ll y=RecrSubSeq(str," ");
	cout<<y;
	return 0;
}
