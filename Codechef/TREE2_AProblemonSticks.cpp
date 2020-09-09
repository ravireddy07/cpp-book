#include <iostream>
#include <algorithm>
using namespace std;

int remove_duplicates(long int arr[], long int l1)
{
    if (l1 == 0 || l1 == 1)
        return l1;

    long int l2[l1], h = 0;
    for (long int i = 0; i < l1 - 1; ++i)
        if (arr[i] != arr[i + 1])
            l2[h++] = arr[i];
    l2[h++] = arr[l1 - 1];
    for (long int i = 0; i < h; ++i)
        arr[i] = l2[i];
    return h;
}

int main()
{
    long int t;
    cin >> t;
    while (t > 0)
    {
        long int n;
        cin >> n;
        long int arr[n];
        for (long int i = 0; i < n; ++i)
            cin >> arr[i];
        sort(arr, arr + n);
        long int l1 = sizeof(arr) / sizeof(arr[0]);
        l1 = remove_duplicates(arr, l1);
        if (arr[0] == 0)
        {
            l1--;
            cout << l1 << endl;
        }
        else
            cout << l1 << endl;
        t--;
    }
    return 0;
}