// https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
    int sumRootToLeaf(TreeNode *root)
    {
        if (!root)
            return 0;
        int sum = 0;
        sumUp(root, sum);
        return sum;
    }

    void sumUp(TreeNode *node, int &sum)
    {
        if (node->left == NULL && node->right == NULL)
            sum += node->val;
        else
        {
            if (node->left)
            {
                node->left->val += 10 * node->val;
                sumUp(node->left, sum);
            }
            if (node->right)
            {
                node->right->val += 10 * node->val;
                sumUp(node->right, sum);
            }
        }
    }
};
