#include <stdio.h>

void swapElements(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int arr[], int lowIndex, int highIndex)
{
    int pivotElement = arr[highIndex];
    int i = (lowIndex - 1);
    for (int j = lowIndex; j <= highIndex - 1; j++)
    {
        if (arr[j] <= pivotElement)
        {
            i++;
            swapElements(&arr[i], &arr[j]);
        }
    }
    swapElements(&arr[i + 1], &arr[highIndex]);
    return (i + 1);
}

void Sort(int arr[], int lowIndex, int highIndex)
{
    if (lowIndex < highIndex)
    {
        int pivot = partition(arr, lowIndex, highIndex);
        Sort(arr, lowIndex, pivot - 1);
        Sort(arr, pivot + 1, highIndex);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int pizzas[n];
        // Taking Input
        for (int i = 0; i < n; ++i)
            scanf("%d", &pizzas[i]);

        int num[n];             // Different Topping's Pizza's
        int cnt[n];             // Different Topping's Pizza's Count/Repetition
        Sort(pizzas, 0, n - 1); //Sorting

        int c = 1, j = 0;
        // Find Different pizza's and their counts.
        for (int i = 1; i < n; i++)
        {
            if (pizzas[i] == pizzas[i - 1])
            {
                c++;
                if (i == n - 1)
                {
                    num[j] = pizzas[i - 1];
                    cnt[j] = c;
                    j++;
                }
            }
            else if (i == n - 1)
            {
                num[j] = pizzas[i - 1];
                cnt[j] = c;
                j++;
                num[j] = pizzas[i];
                cnt[j] = 1;
                j++;
            }
            else
            {
                num[j] = pizzas[i - 1];
                cnt[j] = c;
                c = 1;
                j++;
            }
        }

        for (int i = j; i < n; i++)
        {
            num[i] = -1;
            cnt[i] = -1;
        }

        // Required Order of Pizzes
        int res[n];
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            if (temp == j)
                temp = 0;
            if (cnt[temp] > 0)
            {
                res[i] = num[temp];
                cnt[temp]--;
                temp++;
            }
            else
            {
                temp++;
                i--;
            }
        }

        /*for (int i = 0; i < n; i++)
            printf("%d ", res[i]);
        printf("\n");*/

        // Finding Minimum Distance between two Pizza's
        int min_distance = 100000007;
        int count, k;

        int exit = 0, only_one = 0;
        for (int i = 0; i < n; i++)
        {
            count = 0;
            for (int k = i + 1; k < n; k++)
            {
                if (res[i] != res[k])
                    count++;
                else
                {
                    if (min_distance > count && count > 1)
                        min_distance = count;
                    only_one++;
                    break;
                }
            }
        }

        if (only_one == 1)
            printf("%d\n", n - 2);
        else
            printf("%d\n", (min_distance == 100000007) ? 0 : min_distance);
    }
    return 0;
}
