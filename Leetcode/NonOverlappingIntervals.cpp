#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(vector<int> &a, vector<int> &b)
{
	return a[1] < b[1];
}

class Solution
{
public:
	int eraseOverlapIntervals(vector<vector<int>> &intervals)
	{
		int ans = -1;
		if (intervals.size() == 0)
			return 0;

		sort(intervals.begin(), intervals.end(), comp); //custom comperator is used.
		vector<int> prev = intervals[0];

		for (vector<int> i : intervals)
		{
			if (prev[1] > i[0])
			{
				ans++; //we dont update previous, because i[1] will be grater then prev[1]
			}
			else
				prev = i; // we want the end point to be minimum
		}
		return ans; //ans was initially made -1 because our prev and intervals[0] will always match
	}
};

int main()
{
	vector<vector<int>> intervals{
		{1, 2}, {2, 3}, {3, 4}, {1, 3}};

	Solution a1;
	int result = a1.eraseOverlapIntervals(intervals);
}