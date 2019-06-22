#include<bits/stdc++.h>
using namespace std;

int countFreq(string &Smallstr, string &BigStr) {
	int M = SmallStr.length();
	//int M = SmallStr.sizeof();
	//int M = strlen(SmallStr);	
	int N = BigStr.length();
	int result = 0;

	for (int i=0;i<=N-M;i++) {
		int j;
		for (j = 0; j < M; j++)
			if (BigStr[i+j] != SmallStr[j])
				break;
		if (j == M)	{
			result++;
			j = 0;
		}
	}
	return result;
}


int main() {
string s1 = "eeexaeeeemple";
string s2 = "eee";
cout << countOcc(s2, s1);
return 0;
}
