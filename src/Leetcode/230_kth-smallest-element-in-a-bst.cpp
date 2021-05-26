// Problem Statement: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    void inorder(TreeNode *root, vector<int> &res, int k)
    {
        if (!root || res.size() >= k)
            return;
        inorder(root->left, res, k);
        res.push_back(root->val);
        inorder(root->right, res, k);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> res;
        inorder(root, res, k);
        return res[k - 1];
    }
};
