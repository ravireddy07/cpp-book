#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int getTwiceMedian(vector<int> &A, vector<int> &count, int d)
{
    vector<int> countfreq(count);
    for (int i = 1; i < countfreq.size(); i++) // O(1);
        countfreq[i] += countfreq[i - 1];

    int median;
    int a = 0;
    int b = 0;

    //d is even -> median = a+b
    if (d % 2 == 0)
    {
        int first = d / 2;
        int second = first + 1;
        int i = 0;
        for (; i < 201; i++)
        {
            if (first <= countfreq[i])
            {
                a = i;
                break;
            }
        }

        for (; i < 201; i++)
        {
            if (second <= countfreq[i])
            {
                b = i;
                break;
            }
        }
    }
    else //d is odd -> median = a + 0 = 2*(middle elem)
    {
        int first = d / 2 + 1;
        for (int i = 0; i < 201; i++)
        {
            if (first <= countfreq[i])
            {
                a = 2 * i;
                break;
            }
        }
    }
    median = a + b;
    return median;
}

int activityNotifications(vector<int> A, int d)
{
    int alerts = 0;
    vector<int> count(201, 0); //stores count of last 'd' numbers
    int n = A.size();

    for (int i = 0; i < d; i++)
        count[A[i]]++;
    for (int i = d; i < n; i++)
    {
        int median = getTwiceMedian(A, count, d);
        if (A[i] >= median)
            alerts++;
        //update count array
        count[A[i]]++;
        count[A[i - d]]--;
    }
    return alerts;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);
    int d = stoi(nd[1]);
    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);
    vector<int> expenditure(n);

    for (int i = 0; i < n; i++)
    {
        int expenditure_item = stoi(expenditure_temp[i]);
        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);
    fout << result << "\n";
    fout.close();
    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
