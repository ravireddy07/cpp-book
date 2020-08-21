#include <iostream>
#include <vector>
using namespace std;

class sortArrayByParity
{
public:
    vector<int> Method_1(vector<int> &A)
    {
        vector<int> result;
        //result.reserve(A.size());

        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] % 2 == 0)
            {
                result.insert(result.begin(), A[i]);
            }
            else
            {
                result.insert(result.end(), A[i]);
            }
        }
        return result;
    }

    vector<int> Method_2(vector<int> &A)
    {
        int size = A.size(), start = 0, end = size - 1;
        while (start < end)
        {
            if (A[start] % 2 == 0)
            {
                start++;
            }
            else
            {
                swap(A[start], A[end]);
                end--;
            }
        }
        return A;
    }

    vector<int> Method_3(vector<int> &A)
    {
        vector<int> result;
        //result.reserve(A.size());
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] % 2 == 0)
            {
                result.push_back(A[i]);
            }
        }
        for (int j = 0; j < A.size(); j++)
        {
            if (A[j] % 2 != 0)
            {
                result.push_back(A[j]);
            }
        }
        return result;
    }
};

int main()
{
    vector<int> show;
    vector<int> input = {3, 1, 2, 4};
    sortArrayByParity a;
    show = a.Method_1(input); //Runtime: 60 ms
    show = a.Method_2(input); //Runtime: 16 ms
    show = a.Method_3(input); //Runtime: 12 ms

    cout << "[";
    for (int i = 0; i < show.size(); i++)
    {
        if (i == show.size() - 1)
        {
            cout << show[i];
        }
        else
        {
            cout << show[i] << ", ";
        }
    }
    cout << "]";
}