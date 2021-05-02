// Problem Statement: https://leetcode.com/problems/course-schedule/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(vector<int> adj[], vector<bool> &visited, vector<bool> &current, int currentNode)
    {
        visited[currentNode] = true;
        current[currentNode] = true;
        for (int i = 0; i < adj[currentNode].size(); i++)
        {
            int node = adj[currentNode][i];
            if (visited[node] == false && current[node] == false)
            {
                if (dfs(adj, visited, current, node))
                    return true;
            }
            else if (current[node] == true)
                return true;
        }
        current[currentNode] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        int n = prerequisites.size();
        if (n == 0)
            return true;
        int m = prerequisites[0].size();
        //adjacency list preparation
        vector<int> adj[numCourses];
        for (int i = 0; i < n; i++)
        {
            int x = prerequisites[i][0];
            for (int j = 1; j < m; j++)
                adj[x].push_back(prerequisites[i][j]);
        }
        //doing dfs
        vector<bool> visited(numCourses, false);
        vector<bool> current(numCourses, false);
        for (int i = 0; i < visited.size(); i++)
        {
            if (visited[i] == false)
            {
                if (dfs(adj, visited, current, i) == true)
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> input = {{1, 0}, {0, 1}};
    cout << a.canFinish(2, input) << "\n";
    return 0;
}
