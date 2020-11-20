// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> A, vector<int> B)
    {
        int n = A.size();
        int m = B.size();
        // the following call is to make sure len(A) <= len(B).
        // yes, it calls itself, but at most once, shouldn't be
        // consider a recursive solution
        if (n > m)
            return findMedianSortedArrays(B, A);

        // now, do binary search
        int k = (n + m - 1) / 2;
        int l = 0, r = min(k, n); // r is n, NOT n-1, this is important!!
        while (l < r)
        {
            int midA = (l + r) / 2;
            int midB = k - midA;
            if (A[midA] < B[midB])
                l = midA + 1;
            else
                r = midA;
        }

        // after binary search, we almost get the median because it must be between
        // these 4 numbers: A[l-1], A[l], B[k-l], and B[k-l+1]

        // if (n+m) is odd, the median is the larger one between A[l-1] and B[k-l].
        // and there are some corner cases we need to take care of.
        int a = max(l > 0 ? A[l - 1] : INT_MIN, k - l >= 0 ? B[k - l] : INT_MIN);
        if (((n + m) & 1) == 1)
            return (double)a;

        // if (n+m) is even, the median can be calculated by
        //      median = (max(A[l-1], B[k-l]) + min(A[l], B[k-l+1]) / 2.0
        // also, there are some corner cases to take care of.
        int b = min(l < n ? A[l] : INT_MAX, k - l + 1 < m ? B[k - l + 1] : INT_MAX);
        return (a + b) / 2.0;
    }
};

int main()
{
    Solution a;
    vector<int> in1 = {1, 3}, in2 = {2, 7};
    cout << a.findMedianSortedArrays(in1, in2) << endl;
    return 0;
}
