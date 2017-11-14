#include <stdio.h>

// 24. Swap Nodes in Pairs

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

struct ListNode *swapPairs(struct ListNode *head)
{
	struct ListNode *preNode, *nextNode, *lastNode = NULL;

	preNode = head;
	while (preNode)
	{
		nextNode = preNode->next;
		if (nextNode)
		{
			preNode->next = nextNode->next;
			nextNode->next = preNode;

			if (preNode == head)
			{
				head = nextNode;
			}

			if (lastNode == NULL)
			{
				lastNode = preNode;
			}
			else
			{
				lastNode->next = nextNode;
				lastNode = preNode;
			}
		}
		preNode = preNode->next;
	}

	return head;
}

int main()
{
	return 0;
}