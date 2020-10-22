// https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numTriplets(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        long count = 0, num;
        unordered_map<int, int> ar1, ar2;

        for (int i = 0; i < nums1.size(); i++)
            ar1[nums1[i]]++;
        for (int i = 0; i < nums2.size(); i++)
            ar2[nums2[i]]++;

        for (int i = 0; i < nums1.size(); i++)
        {
            if (i > 0 && nums1[i] == nums1[i - 1])
                continue;
            if (nums1[i] > nums2.back())
                break;
            if (nums1[i] < nums2[0])
                continue;
            num = (long)nums1[i] * nums1[i];

            for (int j = 0; j < nums2.size(); j++)
            {
                if (j > 0 && nums2[j] == nums2[j - 1])
                    continue;
                if (num / nums2[j] < nums2[0])
                    break;
                if (num % nums2[j] == 0 && num / nums2[j] >= nums2[j] && ar2.find(num / nums2[j]) != ar2.end())
                {
                    if (num / nums2[j] == nums2[j])
                    {
                        count += ar1[nums1[i]] * (long)(ar2[nums2[j]] * (ar2[nums2[j]] - 1)) / 2;
                        break;
                    }
                    else
                        count += ar1[nums1[i]] * (long)ar2[nums2[j]] * ar2[num / nums2[j]];
                }
            }
        }

        for (int i = 0; i < nums2.size(); i++)
        {
            if (i > 0 && nums2[i] == nums2[i - 1])
                continue;
            if (nums2[i] > nums1.back())
                break;
            if (nums2[i] < nums1[0])
                continue;

            num = (long)nums2[i] * nums2[i];

            for (int j = 0; j < nums1.size(); j++)
            {
                if (j > 0 && nums1[j] == nums1[j - 1])
                    continue;
                if (num / nums1[j] < nums1[0])
                    break;
                if (num % nums1[j] == 0 && num / nums1[j] >= nums1[j] && ar1.find(num / nums1[j]) != ar1.end())
                {
                    if (num / nums1[j] == nums1[j])
                    {
                        count += ar2[nums2[i]] * (long)(ar1[nums1[j]] * (ar1[nums1[j]] - 1)) / 2;
                        break;
                    }
                    else
                        count += ar2[nums2[i]] * (long)ar1[nums1[j]] * ar1[num / nums1[j]];
                }
            }
        }
        return count;
    }
};

int main()
{
    Solution a;
    vector<int> in1 = {7, 4}, in2 = {5, 2, 8, 9};
    cout << a.numTriplets(in1, in2) << endl;
    return 0;
}