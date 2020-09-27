// https://leetcode.com/problems/design-skiplist/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Skiplist
{
private:
    struct ListNode
    {
        int val = {0};
        ListNode *next = {NULL}, *down = {NULL};
        ListNode() {}
        ListNode(int v, ListNode *n, ListNode *d) : val(v), next(n), down(d) {}
    };

    ListNode dummy, *head;

public:
    Skiplist() : head(&dummy) {}

    // Find node traversal from top to bottom layer
    bool search(int target)
    {
        for (auto *node = head; node; node = node->down)
        { // for-each layer
            for (; node->next && target > node->next->val; node = node->next)
                ; // find the pre-node for the current num

            if (node->next && node->next->val == target)
                return true;
        }

        return false;
    }

    // 1. Find the preNode, traversal from the top layer to the bottom layer
    //   - For the node we go down, save it into a temporary buffer, like [p1, p2, p3...]
    // 2. Append list node after the preNode, then reverse add the node to upper layer in 50% chance
    // 3. Lastly, we appended all preNodes and the random number is 1, then we create a new layer on the top
    void add(int num)
    {
        // 1. traversal from top to bottom and save all the preNodes
        vector<ListNode *> preNodes;

        for (auto *node = head; node; node = node->down)
        { // for-each layer
            for (; node->next && num > node->next->val; node = node->next)
                ; // find the pre-node for the current num

            preNodes.push_back(node);
        }

        // 2. reverse append nodes from bottom layer up to top (randomly 50%)
        // - for the bottom layer, we have to 100% append the node
        // - upon the bottom layer, we reverse append node in 50% chance
        bool rnd = true;
        ListNode *down = NULL;

        for (ListNode *pre = NULL; rnd && !preNodes.empty(); rnd = rand() & 1, preNodes.pop_back(), down = pre->next)
        {
            pre = preNodes.back();
            pre->next = new ListNode(num, pre->next, down);
        }

        // 3. lastly, if rnd == 1, create a new layer on top of current layers
        if (rnd)
        {
            head = new ListNode(0, new ListNode(num, NULL, down), head);
        }
    }

    // 1. Find the node from top layer to bottom
    // 2. If we find it, delete it and then delete all the nodes down below if have
    bool erase(int num)
    {
        bool found = false;

        for (auto *node = head; node; node = node->down)
        { // for each layer
            for (; node->next && num > node->next->val; node = node->next)
                ;

            if (node->next && node->next->val == num)
            {
                found = true;
                node->next = node->next->next;
            }
        }

        return found;
    }
};

int main()
{
    Skiplist *obj = new Skiplist();
    obj->add(1);
    obj->add(2);
    obj->add(3);
    bool param_1 = obj->search(0);
    obj->add(0);
    obj->add(4);
    bool param_3 = obj->erase(0);
    cout << param_1 << " " << param_3 << endl;
    return 0;
}
