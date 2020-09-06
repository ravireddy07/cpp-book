// https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/

#include <iostream>
#include <vector>
using namespace std;

class UnionFind
{
    vector<int> id;
    int size;

public:
    UnionFind(int N) : id(N)
    {
        iota(begin(id), end(id), 0);
        size = N;
    }
    int find(int a)
    {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    int connected(int a, int b)
    {
        return find(a) == find(b);
    }
    void connect(int a, int b)
    {
        int p = find(a), q = find(b);
        if (p == q)
            return;
        id[p] = q;
        --size;
    }
    int getSize() { return size; }
};

class Solution
{
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &E)
    {
        UnionFind a(n), b(n);
        int ans = 0;
        for (auto &e : E)
        {
            if (e[0] != 3)
                continue;
            int u = e[1] - 1, v = e[2] - 1;
            if (a.connected(u, v))
            {
                ++ans;
                continue;
            }
            a.connect(u, v);
            b.connect(u, v);
        }
        for (auto &e : E)
        {
            int u = e[1] - 1, v = e[2] - 1;
            if (e[0] == 1)
            {
                if (a.connected(u, v))
                    ++ans;
                else
                    a.connect(u, v);
            }
            else if (e[0] == 2)
            {
                if (b.connected(u, v))
                    ++ans;
                else
                    b.connect(u, v);
            }
        }
        return a.getSize() != 1 || b.getSize() != 1 ? -1 : ans;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> input = {{3, 1, 2}, {3, 2, 3}, {1, 1, 4}, {2, 1, 4}};
    cout << a.maxNumEdgesToRemove(4, input) << endl;
    return 0;
}