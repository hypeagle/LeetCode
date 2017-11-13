#include <stdio.h>
#include <stdlib.h>

// 23. Merge k Sorted Lists

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

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize)
{
	struct ListNode *reList = NULL, *indexList = NULL;
	struct ListNode *minNode;
	int i, minIndex;

	if (listsSize <= 0)
	{
		return NULL;
	}

	minNode = lists[0];
	minIndex = 0;
	for (i = 1; i < listsSize; i++)
	{
		if (minNode == NULL)
		{
			minNode = lists[i];
			minIndex = i;
		}
		else if (lists[i] && minNode->val > lists[i]->val)
		{
			minNode = lists[i];
			minIndex = i;
		}
	}
	if (minNode)
	{
		reList = minNode;

		lists[minIndex] = lists[minIndex]->next;
		indexList = minNode;
		indexList->next = NULL;
	}

	while (1)
	{
		minNode = lists[0];
		minIndex = 0;
		for (i = 1; i < listsSize; i++)
		{
			if (minNode == NULL)
			{
				minNode = lists[i];
				minIndex = i;
			}
			else if (lists[i] && minNode->val > lists[i]->val)
			{
				minNode = lists[i];
				minIndex = i;
			}
		}
		if (minNode)
		{
			lists[minIndex] = lists[minIndex]->next;
			indexList->next = minNode;

			indexList = minNode;
			indexList->next = NULL;
		}
		else
		{
			break;
		}
	}

	return reList;
}

int main()
{
	return 0;
}