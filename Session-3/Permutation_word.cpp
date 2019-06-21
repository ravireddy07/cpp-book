#include <iostream>
using namespace std;

int result = 0;
void permut(string str, string output) {
	if(str.size() == 0) {
		cout<<output<<endl;
		result++;
		return;
	}

    for(int i=0;i<str.size();i++){
        char ch=str[0];
        string rof = str.substr(0,i) + str.substr(i+1);
        permut(rof, ch+output);
    }
}


int main(int argc, char const *argv[])
{
	/* code */
	string word;
	cin>>word;
    permut(word,"");
    cout<<result;
	return 0;
}
