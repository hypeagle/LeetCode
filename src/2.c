#include <stdio.h>
#include <stdlib.h>

// 2. Add Two Numbers

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode
{
	int val;
	struct ListNode *next;
};
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode *retHead = NULL;
	struct ListNode *retList = NULL;
	struct ListNode *tmpList = NULL;
	struct ListNode *p1, *p2;

	p1 = l1;
	p2 = l2;

	int value = 0;
	while (1)
	{
		if (p1 == NULL && p2 == NULL)
		{
			break;
		}

		if (p1)
		{
			value += p1->val;
			p1 = p1->next;
		}

		if (p2)
		{
			value += p2->val;
			p2 = p2->next;
		}

		tmpList = (struct ListNode *)malloc(sizeof(struct ListNode));
		tmpList->next = NULL;
		tmpList->val = value % 10;
		value = value / 10;

		if (retHead == NULL)
		{
			retHead = tmpList;
			retList = tmpList;
		}
		else
		{
			retList->next = tmpList;
			retList = tmpList;
		}
	}

	if (value > 0)
	{
		tmpList = (struct ListNode *)malloc(sizeof(struct ListNode));
		tmpList->next = NULL;
		tmpList->val = value % 10;
		value = value / 10;

		if (retHead == NULL)
		{
			retHead = tmpList;
			retList = tmpList;
		}
		else
		{
			retList->next = tmpList;
			retList = tmpList;
		}
	}

	return retHead;
}

int main()
{
	return 0;
}