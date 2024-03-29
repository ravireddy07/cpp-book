#include <bits/stdc++.h>
using namespace std;

bool targetSubset(int *arr, int n, int tw)
{
	bool dp[n + 1][tw + 1];
	for (int i = 0; i <= tw; i++)
		dp[0][i] = 0;
	for (int i = 0; i <= n; i++)
		dp[i][0] = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= tw; j++)
		{
			if (arr[i - 1] > j)
				dp[i][j] = dp[i - 1][j];
			else if (arr[i - 1] == j)
				dp[i][j] = 1;
			else
				dp[i][j] = dp[i - 1][j] or dp[i - 1][j - arr[i - 1]];
		}
	}

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= tw; j++)
			cout << dp[i][j] << " ";
		cout << "\n";
	}
	return dp[n][tw];
}

int main(int argc, char const *argv[])
{
	int n, tw;
	cin >> n >> tw;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << targetSubset(arr, n, tw) << "\n";
	return 0;
}
