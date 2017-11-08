#include <stdio.h>
#include <stdlib.h>

// 4. Median of Two Sorted Arrays

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
	// TC: O(m+n), SC: O(m+n)
	// AT: 32 ms
	// double retMedian;

	// int *totalNums = malloc((nums1Size + nums2Size) * sizeof(int));
	// int indexOne = 0, indexTwo = 0, indexTotal = (nums1Size + nums2Size);
	// int i, median;

	// for(i = 0; i < indexTotal; i++) {
	//     if(indexOne >= nums1Size) {
	//         totalNums[i] = nums2[indexTwo++];
	//     } else if(indexTwo >= nums2Size) {
	//         totalNums[i] = nums1[indexOne++];
	//     } else if(nums1[indexOne] < nums2[indexTwo]) {
	//         totalNums[i] = nums1[indexOne++];
	//     } else {
	//         totalNums[i] = nums2[indexTwo++];
	//     }
	// }

	// if(indexTotal & 0x1) {
	//     median = indexTotal >> 1;
	//     retMedian = totalNums[median] / 1.0;
	// } else {
	//     median = indexTotal >> 1;
	//     retMedian = (totalNums[median] + totalNums[median - 1]) / 2.0;
	// }

	// free(totalNums);
	// return retMedian;

	// TC: O(log(m+n)), SC: O(1)
	// AT: 35 ms
	double retMedian;

	int *numsOne, *numsTwo, numsOneSize, numsTwoSize;
	int iMin, iMax, iHalf;
	int i, j;
	int maxLeft, minRight;

	if (nums1Size < nums2Size)
	{
		numsOne = nums1;
		numsOneSize = nums1Size;
		numsTwo = nums2;
		numsTwoSize = nums2Size;
	}
	else
	{
		numsOne = nums2;
		numsOneSize = nums2Size;
		numsTwo = nums1;
		numsTwoSize = nums1Size;
	}

	iMin = 0;
	iMax = numsOneSize;
	iHalf = (numsOneSize + numsTwoSize + 1) >> 1;

	while (iMin <= iMax)
	{
		i = (iMin + iMax) >> 1;
		j = iHalf - i;

		if (i < iMax && numsOne[i] < numsTwo[j - 1])
		{
			iMin++;
		}
		else if (i > iMin && numsOne[i - 1] > numsTwo[j])
		{
			iMax--;
		}
		else
		{
			maxLeft = 0;
			minRight = 0;

			if (i == 0)
			{
				maxLeft = numsTwo[j - 1];
			}
			else if (j == 0)
			{
				maxLeft = numsOne[i - 1];
			}
			else
			{
				maxLeft = numsOne[i - 1] > numsTwo[j - 1] ? numsOne[i - 1] : numsTwo[j - 1];
			}

			if (i == numsOneSize)
			{
				minRight = numsTwo[j];
			}
			else if (j == numsTwoSize)
			{
				minRight = numsOne[i];
			}
			else
			{
				minRight = numsOne[i] < numsTwo[j] ? numsOne[i] : numsTwo[j];
			}

			if ((numsOneSize + numsTwoSize) & 0x1)
			{
				retMedian = maxLeft / 1.0;
			}
			else
			{
				retMedian = (maxLeft + minRight) / 2.0;
			}

			break;
		}
	}

	return retMedian;
}

int main()
{
	return 0;
}