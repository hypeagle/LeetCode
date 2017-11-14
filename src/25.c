#include <stdio.h>

// 25. Reverse Nodes in k-Group

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

struct ListNode *reverseKGroup(struct ListNode *head, int k)
{
	struct ListNode *beforePreNode = NULL, *preNode = NULL, *nextNode = NULL, *afterNextNode = NULL;
	struct ListNode *groupHeadNode = NULL, *groupTrailNode = NULL;
	struct ListNode *tmpNode;

	int i;

	if (k > 1)
	{
		preNode = head;
		while (preNode)
		{
			tmpNode = preNode;
			for (i = 0; i < k; i++)
			{
				if (tmpNode == NULL)
				{
					break;
				}
				tmpNode = tmpNode->next;
			}

			if (i == k)
			{
				nextNode = preNode->next;
				if (nextNode)
				{
					groupTrailNode = preNode;
					groupTrailNode->next = NULL;
					for (i = 1; i < k; i++)
					{
						if (nextNode)
						{
							afterNextNode = nextNode->next;
							groupHeadNode = nextNode;
							nextNode->next = preNode;

							preNode = groupHeadNode;
							nextNode = afterNextNode;
						}
					}

					if (head == groupTrailNode)
					{
						head = groupHeadNode;
					}

					if (beforePreNode)
					{
						beforePreNode->next = groupHeadNode;
					}
					beforePreNode = groupTrailNode;
				}

				preNode = afterNextNode;
			}
			else     // If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
			{
				if (beforePreNode)
				{
					beforePreNode->next = preNode;
				}
				break;
			}
		}
	}

	return head;
}

int main()
{
	return 0;
}