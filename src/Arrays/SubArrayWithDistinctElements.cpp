#include <bits/stdc++.h>
using namespace std;

int sumOflength(int *arr, int n)
{
    unordered_set<int> s;
    int j = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (j < n and s.find(arr[j]) == s.end())
        {
            s.insert(arr[j]);
            j++;
        }
        ans += ((j - i) * (j - i + 1)) / 2;
        s.erase(arr[i]);
    }
    return ans;
}

int main()
{
    int arr[] = {1, 4, 2, 6, 8, 4, 9, 3, 2, 8};
    cout << sumOflength(arr, sizeof(arr) / sizeof(arr[0])) << endl;
    return 0;
}
