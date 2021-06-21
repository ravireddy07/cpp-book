// Problem Statement: https://leetcode.com/problems/employee-importance/

#include <bits/stdc++.h>
using namespace std;

class Employee
{
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution
{
public:
    int pos(vector<Employee *> employees, int id)
    {
        for (int i = 0; i < employees.size(); i++)
            if (employees[i]->id == id)
                return i;
        return 0;
    }
    int getImportance(vector<Employee *> employees, int id)
    {
        vector<int> child;
        int p = pos(employees, id);
        child = employees[p]->subordinates;
        int sum = employees[p]->importance;
        if (child.size() == 0)
            return sum;

        for (int i = 0; i < child.size(); i++)
            sum += getImportance(employees, child[i]);
        return sum;
    }
};

int main()
{
    Solution a;
    cout << a.getImportance({{1, 5, {2, 3}}, {2, 3, {}}, {3, 3, {}}}, 1) << "\n";
    return 0;
}
