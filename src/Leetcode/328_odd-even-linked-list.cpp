// https://leetcode.com/problems/odd-even-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *odd = head, *even = head->next, *temp, *e = head->next;
        while (true)
        {
            if (odd->next != NULL && odd->next->next != NULL)
            {
                temp = odd->next->next;
                odd->next = temp;
                odd = temp;
                cout << odd->val << endl;
                if (temp->next != NULL)
                {
                    even->next = temp->next;
                    even = temp->next;
                    cout << even->val << endl;
                }
                else
                    even->next = NULL;
            }
            if (even->next == NULL)
            {
                odd->next = e;
                break;
            }
        }
        return head;
    }
};
