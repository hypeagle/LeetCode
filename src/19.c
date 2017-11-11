#include <stdio.h>
#include <stdlib.h>

// 19. Remove Nth Node From End of List

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

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
	struct ListNode *retHead = head;
	struct ListNode *delNode = head, *indexNode = head->next;
	struct ListNode *preNode;
	int index, delIndex;

	index = 1;
	delIndex = 0;
	while (indexNode)
	{
		indexNode = indexNode->next;
		index ++;
		if (index - delIndex > n)
		{
			delIndex ++;
			preNode = delNode;
			delNode = delNode->next;
		}
	}

	if (delNode == retHead)
	{
		retHead = retHead->next;
	}
	else
	{
		preNode->next = delNode->next;
	}

	free(delNode);
	return retHead;
}

int main()
{
	return 0;
}