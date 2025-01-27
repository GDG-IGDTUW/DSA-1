#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *slow = head, *fast = head;

        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }

        if (fast == nullptr)
        {
            return head->next;
        }

        while (fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *delNode = slow->next;
        slow->next = slow->next->next;

        delete delNode;
        return head;
    }
};