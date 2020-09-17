// https://leetcode.com/problems/island-perimeter/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    struct Point
    {
        int i, j;
        Point(int _i, int _j)
        {
            i = _i;
            j = _j;
        }
        Point(const Point &other) = default;
    };
    vector<Point> isl;
    int perim;

public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        perim = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] == 1)
                    isl.push_back(Point(i, j));
        for (auto &is : isl)
        {
            if (is.i == 0)
                perim++;
            if (is.j == 0)
                perim++;
            if (is.i == grid.size() - 1)
                perim++;
            if (is.j == grid[is.i].size() - 1)
                perim++;
            if (is.i - 1 >= 0)
                if (grid[is.i - 1][is.j] == 0)
                    perim++;
            if (is.i + 1 <= grid.size() - 1)
                if (grid[is.i + 1][is.j] == 0)
                    perim++;
            if (is.j - 1 >= 0)
                if (grid[is.i][is.j - 1] == 0)
                    perim++;
            if (is.j + 1 <= grid[is.i].size() - 1)
                if (grid[is.i][is.j + 1] == 0)
                    perim++;
        }
        return perim;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> input = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    cout << a.islandPerimeter(input) << endl;
    return 0;
}