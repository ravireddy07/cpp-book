// Problem Statement: https://leetcode.com/problems/binary-tree-right-side-view/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Pre-order Traversal
class Solution
{
public:
	void recursion(TreeNode *root, int level, vector<int> &res)
	{
		if (root == NULL)
			return;
		if (res.size() < level)
			res.push_back(root->val);
		recursion(root->right, level + 1, res);
		recursion(root->left, level + 1, res);
	}

	vector<int> rightSideView(TreeNode *root)
	{
		vector<int> res;
		recursion(root, 1, res);
		return res;
	}
};

// DFS
class Solution
{
public:
	vector<int> rightSideView(TreeNode *root)
	{
		vector<int> view;
		rightView(root, view, 0);
		return view;
	}

private:
	void rightView(TreeNode *root, vector<int> &view, int level)
	{
		if (!root)
		{
			return;
		}
		if (view.size() == level)
		{
			view.push_back(root->val);
		}
		rightView(root->right, view, level + 1);
		rightView(root->left, view, level + 1);
	}
};

//BFS
class Solution
{
public:
	vector<int> rightSideView(TreeNode *root)
	{
		if (!root)
		{
			return {};
		}
		vector<int> view;
		queue<TreeNode *> todo;
		todo.push(root);
		while (!todo.empty())
		{
			int n = todo.size();
			for (int i = 0; i < n; i++)
			{
				TreeNode *node = todo.front();
				todo.pop();
				if (i == n - 1)
				{
					view.push_back(node->val);
				}
				if (node->left)
				{
					todo.push(node->left);
				}
				if (node->right)
				{
					todo.push(node->right);
				}
			}
		}
		return view;
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Solution a;
	vector<int> input = {1, 2, 3, -1, 5, -1, 4};
	vector<int> res;
	res = a.rightSideView(input);
	for (auto i : res)
		cout << i << " ";
	return 0;
}
