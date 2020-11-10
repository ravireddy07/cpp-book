#include <bits/stdc++.h>
using namespace std;

int sum(vector<int> arr, int n)
{
    int res = 0, sum = 0, ok;
    vector<int> v;
    for (int k = 0; k < n; k++)
    {
        for (int i = k; i < n; i++)
        {
            ok = 1;
            for (int j = 0; j < v.size(); j++)
                if (v[j] == arr[i])
                    ok = 0;
            if (ok)
            {
                v.push_back(arr[i]);
                sum += arr[i];
            }
            else
                break;
        }
        if (sum > res)
            res = sum;
        v.erase(v.begin(), v.end());
        sum = 0;
    }
    return res;
}

int main()
{
    vector<int> ar = {1, 4, 2, 6, 8, 4, 9, 3, 2, 8};
    cout << sum(ar, ar.size()) << endl;
    return 0;
}
