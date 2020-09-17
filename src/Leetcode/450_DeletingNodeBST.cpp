// https://leetcode.com/problems/delete-node-in-a-bst/

/*

Sample Input:

root = [5,3,6,2,4,null,7]
key = 3

Sample Output: 

[5,4,6,2,null,null,7]
or
[5,2,6,null,4,null,7]
*/

class Solution
{
public:
    TreeNode *Modify_node(TreeNode *&left, TreeNode *&right)
    {
        if (left == nullptr)
            return right;
        left->right = Modify_node(left->right, right);
        return left;
    }
    TreeNode *deleteNode(TreeNode *&root, int key)
    {
        if (root == nullptr)
            return nullptr;
        if (root->val == key)
        {
            return Modify_node(root->left, root->right);
        }
        if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else
            root->right = deleteNode(root->right, key);
        return root;
    }
};