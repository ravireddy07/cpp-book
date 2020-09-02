// https://leetcode.com/problems/sum-of-left-leaves

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    vector<int> sum;

    void sol(TreeNode *root, bool l)
    {
        if (root != nullptr)
        {
            if (!root->left && !root->right && l)
                sum.push_back(root->val);

            sol(root->left, true);
            sol(root->right, false);
        }
    }

public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        sol(root, false);
        return accumulate(sum.begin(), sum.end(), 0);
    }
};
