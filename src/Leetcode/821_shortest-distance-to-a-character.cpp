// https://leetcode.com/problems/shortest-distance-to-a-character/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int left(string s, char c, int pos) {
		int cnt = 0;
		for (int i = pos; i >= 0; i--) {
			if (s[i] == c)
				return cnt;
			else
				cnt++;
		}
		return INT_MAX;
	}

	int right(string s, char c, int pos) {
		int cnt = 0;
		for (int i = pos; i < s.size(); i++) {
			if (s[i] == c)
				return cnt;
			else
				cnt++;
		}
		return INT_MAX;
	}

	// Brute force
	vector<int> shortestToChar(string s, char c) {
		vector<int> res;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == c)
				res.push_back(0);
			else
				res.push_back(min(left(s, c, i), right(s, c, i)));
		}
		return res;
	}

	// Optimal
	vector<int> shortestToChar(string S, char C) {
		int n = S.size(), pos = -n;
		vector<int> res(n, n);
		for (int i = 0; i < n; ++i) {
			if (S[i] == C) pos = i;
			res[i] = i - pos;
		}
		for (int i = pos - 1; i >= 0; --i) {
			if (S[i] == C)  pos = i;
			res[i] = min(res[i], pos - i);
		}
		return res;
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Solution a;
	vector<int> res = a.shortestToChar("loveleetcode", 'c');
	for (auto i : res)
		cout << i << " ";
	return 0;
}
