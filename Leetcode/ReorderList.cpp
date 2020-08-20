#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct ListNode
{
    *int val;
    *ListNode *next;
    *ListNode() : val(0), next(nullptr){} * ListNode(int x) : val(x), next(nullptr){} * ListNode(int x, ListNode *next) : val(x), next(next){}
                                                                                                                                      *
};

class Solution
{
public:
    //The recursive code:
    void reorderList(ListNode *head)
    {
        // base case handled here
        if (!head || !head->next || !head->next->next)
            return;
        // we need to find the penultimate node in order to proceed
        ListNode *penultimate = head;
        while (penultimate->next->next)
            penultimate = penultimate->next;
        // then we move it in the second spot
        penultimate->next->next = head->next;
        head->next = penultimate->next;
        // and set penultimate to be the last
        penultimate->next = NULL;
        // and then we proceed with the rest, same way
        reorderList(head->next->next);
    }

    /*//The iterative code:
    void reorderList(ListNode *head)
    {
        // we need to find the penultimate node in order to proceed
        ListNode *penultimate;
        while (head && head->next && head->next->next)
        {
            penultimate = head;
            while (penultimate->next->next)
                penultimate = penultimate->next;
            // then we move it in the second spot
            penultimate->next->next = head->next;
            head->next = penultimate->next;
            // and set penultimate to be the last
            penultimate->next = NULL;
            head = head->next->next;
        }
    }*/
    void printlist(ListNode head)
    {
        while (head != NULL)
        {
            cout << head->data << " ";
            if (head->next)
                cout << "-> ";
            head = head->next;
        }
        cout << endl;
    }
};