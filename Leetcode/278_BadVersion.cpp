// https://leetcode.com/problems/first-bad-version/

#include <iostream>
using namespace std;

class Solution
{
public:
    int firstBadVersion(int n)
    {
        if (n == 1)
            return 1;
        return fbv(1, n);
    }
    int fbv(int start, int end)
    {
        if (start > end)
            return -1;

        int mid = start + (end - start) / 2;

        if (isBadVersion(mid) && !isBadVersion(mid - 1))
            return mid;

        if (!isBadVersion(mid))
            return fbv(mid + 1, end);
        return fbv(start, mid - 1);
    }
};

int main()
{
    Solution a;
    cout << a.firstBadVersion(3) << endl;
    return 0;
}