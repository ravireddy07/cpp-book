// https://leetcode.com/problems/simplify-path/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		vector<string> dir;      // directory names
		string name;             // current directory name
		if (path.back() != '/')  // pad '/' to indicate the end of directory name
			path.push_back('/');
		for (int i = 1; i < path.size(); ++i)
			if (path[i] == '/') {
				if (name == ".." && !dir.empty())  // to parent directory (except for "/")
					dir.pop_back();
				else if (name != "." && name != ".." && name != "")  // a new directory name
					dir.push_back(name);
				name = "";       // reset current directory name
			}
			else
				name += path[i];
		string ret = "/";        // simplified result string
		for (int i = 0; i < dir.size(); ++i) {
			ret += dir[i];
			if (i != dir.size() - 1)
				ret += "/";
		}
		return ret;
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Solution a;
	int t;
	cin >> t;

	while (t--) {
		// input
		// input
		cout << a.simplifyPath("/home//foo/") << "\n";
	}
	return 0;
}
