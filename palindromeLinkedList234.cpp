#include "template.hpp"



/**
 * Note: Reverse the half of the linked list
 * 
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode *head)
{
    ListNode *slow = head, *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *prev = slow;
    slow = slow->next;
    prev->next = NULL;

    ListNode *tmp;
    while (slow)
    {
        tmp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = tmp;
    }

    fast = head;
    slow = prev;
    while (slow)
    {
        if (fast->val != slow->val)
            return false;
        fast = fast->next;
        slow = slow->next;
    }
    return true;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(1);

    std::cout << isPalindrome(head);

    return 0;
}