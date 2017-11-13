#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *retList = NULL, *indexList = NULL;
    struct ListNode *first = l1, *two = l2;

    if(first == NULL) {
        return two;
    } else if(two == NULL) {
        return first;
    } else if(first->val > two->val) {
        retList = two;
        two = two->next;

        retList->next = NULL;
        indexList = retList;
    } else {
        retList = first;
        first = first->next;

        retList->next = NULL;
        indexList = retList;
    }

    while(first || two) {
        if(first == NULL) {
            indexList->next = two;
            two = two->next;

            indexList = indexList->next;
            indexList->next = NULL;
        } else if(two == NULL) {
            indexList->next = first;
            first = first->next;

            indexList = indexList->next;
            indexList->next = NULL;
        } else if(first->val > two->val) {
            indexList->next = two;
            two = two->next;

            indexList = indexList->next;
            indexList->next = NULL;
        } else {
            indexList->next = first;
            first = first->next;

            indexList = indexList->next;
            indexList->next = NULL;
        }
    }

    return retList;
}

int main()
{
    return 0;
}