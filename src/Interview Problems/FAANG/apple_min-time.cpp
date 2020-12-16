/*
Problem Statement:

The computing cluster has multiple processors, each with 4 cores. The number of tasks to handle is equal to the
number of cores in the cluster. Each task has a predicted execution time and each processor has a specified time 
when its core becomes available. Assuming that exactly 4 tasks are assigned to each processor ans those tasks run
independently(asynchronously) on the cores of the chosen processor.

What is the earliest time taht all tasks can be processed.

Sample Test Cases:

Sample: #1

ProcessorTime : {8,10}
taskTime : {2,2,3,1,8,7,4,5}

Output:
16


Sample: #2

ProcessorTime : {10,20}
taskTime : {2,3,1,2,5,8,4,3}

Output:
23

*/

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int minTime(vector<int> processorTime, vector<int> taskTime)
{
    sort(processorTime.begin(), processorTime.end());
    sort(taskTime.begin(), taskTime.end());
    reverse(taskTime.begin(), taskTime.end());
    int ans = 0;
    int curTask = 0;

    for (int procTime : processorTime)
    {
        for (int i = 0; i < 4; ++i)
        {
            int completionTime = taskTime[curTask] + procTime;
            curTask++;
            ans = max(ans, completionTime);
        }
    }
    return ans;
}

int main()
{
    cout << minTime({8, 10}, {2, 2, 3, 1, 8, 7, 4, 5}) << endl;
    return 0;
}
