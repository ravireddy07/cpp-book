/*
a
b
c
a b
b c
a c
a b c
*/
#include<iostream>
using namespace std;

void subseq(string str, string osf){
	//Base Case
	if(str.length()==0){  //str.size()
		cout<<osf<<endl;
		return;
	}
	//Assumption
	char ch = str[0]; //First Character
	string ros = str.substr(1);

	//Self Work
	subseq(ros,osf+ch);
	subseq(ros,osf);
	return;
}

int main(int argc, char const *argv[]){
	subseq("abcde","");
	//string str;
	//cin>>str;
	//subseq(str,"");
	return 0;
}
