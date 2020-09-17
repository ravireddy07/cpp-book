// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

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
public:
    int ans = 0;
    void solve(TreeNode *root, string str)
    {
        if (root == NULL)
            return;
        if (root->left == NULL and root->right == NULL)
        {
            int sum = 0;
            str = to_string(root->val) + str;
            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] == '1')
                    sum = sum + pow(2, i);
            }
            ans += sum;
            return;
        }
        str = to_string(root->val) + str;
        solve(root->left, str);
        solve(root->right, str);
    }
    int sumRootToLeaf(TreeNode *root)
    {
        solve(root, "");
        return ans;
    }
};