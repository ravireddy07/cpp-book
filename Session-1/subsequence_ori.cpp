#include <iostream>
using namespace std;

int result = 0;
void subsequence(string str, string osf) {
	// Base
	if(str.size() == 0) {
		cout<<osf<<endl;
		result++;
		return;
	}

  char ch = str[0]; // First character
	string ros = str.substr(1);
	// Self work
	subsequence(ros, osf+ch);
	subsequence(ros, osf);
}

int main(int argc, char const *argv[])
{
	string str;
	cin>>str;
	subsequence(str, "");
	cout<<result;
	return 0;
}
