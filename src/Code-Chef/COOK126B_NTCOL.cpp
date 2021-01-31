// Problem Statement: https://www.codechef.com/COOK126B/problems/NTCOL

#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#define int long long int
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

int32_t main()
{
	fastio;
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, r, g, b;
		cin >> n >> m >> r >> g >> b;
		char ans[n][m];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				ans[i][j] = '.';
			}
		}
		if (r <= g && r <= b)
		{
			bool flag = false;
			if (b < g) flag = true;

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if ((i + j) % 2 == 0)
					{
						if (r > 0)
						{
							ans[i][j] = 'R';
							r--;
						}
					}
					else
					{
						if (!flag)
						{
							if (g == 0) continue;
							ans[i][j] = 'G';
							g--;
						}
						else
						{
							if (b == 0) continue;
							ans[i][j] = 'B';
							b--;
						}
					}
				}
			}

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (ans[i][j] != '.') continue;
					if (b > 0)
					{
						ans[i][j] = 'B';
						b--;
					}
					else if (g > 0)
					{
						ans[i][j] = 'G';
						g--;
					}
					else
					{
						ans[i][j] = 'R';
						r--;
					}
				}
			}
		}
		else if (g <= r && g <= b)
		{
			bool flag = false;
			if (b < r) flag = true;

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if ((i + j) % 2 == 0)
					{
						if (g > 0)
						{
							ans[i][j] = 'G';
							g--;
						}
					}
					else
					{
						if (!flag)
						{
							if (r > 0)
							{
								ans[i][j] = 'R';
								r--;
							}
						}

						else
						{
							if (b > 0)
							{
								ans[i][j] = 'B';
								b--;
							}
						}
					}
				}
			}

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (ans[i][j] != '.') continue;
					if (r > 0)
					{
						ans[i][j] = 'R';
						r--;
					}
					else if (b > 0)
					{
						ans[i][j] = 'B';
						b--;
					}
					else
					{
						ans[i][j] = 'G';
						g--;
					}
				}
			}
		}
		else
		{
			bool flag = false;
			if (g < r) flag = true;

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if ((i + j) % 2 == 0)
					{
						if (b > 0)
						{
							ans[i][j] = 'B';
							b--;
						}
					}
					else
					{
						if (!flag)
						{
							if (r > 0)
							{
								ans[i][j] = 'R';
								r--;
							}
						}

						else
						{
							if (g > 0)
							{
								ans[i][j] = 'G';
								g--;
							}
						}
					}
				}
			}

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (ans[i][j] != '.')
						continue;
					if (r > 0)
					{
						ans[i][j] = 'R';
						r--;
					}
					else if (g > 0)
					{
						ans[i][j] = 'G';
						g--;
					}
					else
					{
						ans[i][j] = 'B';
						b--;
					}
				}
			}

		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				cout << ans[i][j];
			cout << '\n';
		}

	}
	return 0;
}