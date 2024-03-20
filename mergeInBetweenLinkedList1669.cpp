#include "template.hpp"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
{
    ListNode *curr = list1;
    b = b - a;
    --a;
    while (a--)
        curr = curr->next;
    ListNode *temp = curr->next;
    curr->next = list2;
    while (b--)
        temp = temp->next;

    while (list2->next)
        list2 = list2->next;

    list2->next = temp->next;

    return list1;
}

void addNode(ListNode *&l, int val)
{
    if (l == NULL)
    {
        l = new ListNode(val);
        return;
    }

    ListNode *temp = l;
    while (temp->next)
    {
        temp = temp->next;
    }

    temp->next = new ListNode(val);
}

int main()
{
    ListNode *list1 = NULL;
    addNode(list1, 0);
    addNode(list1, 1);
    addNode(list1, 2);
    addNode(list1, 3);
    addNode(list1, 4);
    addNode(list1, 5);
    addNode(list1, 6);

    ListNode *list2 = NULL;
    addNode(list2, 10);
    addNode(list2, 11);
    addNode(list2, 12);
    addNode(list2, 13);
    addNode(list2, 14);

    int a = 2, b = 5;

    ListNode *l = mergeInBetween(list1, a, b, list2);

    while (l)
    {
        std::cout << l->val << " ";
        l = l->next;
    }

    return 0;
}