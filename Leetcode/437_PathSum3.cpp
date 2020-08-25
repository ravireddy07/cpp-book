#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int ans;
    unordered_map<int, int> mp;
    void count(TreeNode *root, int target, int x)
    {
        if (root == nullptr)
            return;
        if (mp.count((x + root->val) - target) != 0)
        {
            ans += mp[(x + root->val) - target];
        }
        mp[root->val + x]++;
        count(root->left, target, root->val + x);
        count(root->right, target, root->val + x);
        mp[root->val + x]--;
    }
    int pathSum(TreeNode *root, int sum)
    {
        ans = 0;
        mp[0]++;
        count(root, sum, 0);
        mp.clear();
        return ans;
    }
};