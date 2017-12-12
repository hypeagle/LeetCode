#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 45. Jump Game II


int jump(int *nums, int numsSize)
{
	// int retValue = 0;
	// if(numsSize <= 0) {
	//     return retValue;
	// }

	// int i, j;
	// unsigned int *retArray = (unsigned int *)malloc(numsSize * sizeof(unsigned int));
	// memset(retArray, 0xFF, numsSize * sizeof(unsigned int));

	// retArray[0] = 0;
	// for(i = 0; i < numsSize; i++) {
	//     for(j = 1; j <= nums[i]; j++) {
	//         if((i + j) >= numsSize) {
	//             break;
	//         }
	//         if(retArray[i + j] > (retArray[i] + 1)) {
	//             retArray[i + j] = retArray[i] + 1;

	//             if((i + j) == (numsSize - 1)) {
	//                 retValue = retArray[numsSize - 1];
	//                 free(retArray);

	//                 return retValue;
	//             }
	//         }
	//     }
	// }

	// retValue = retArray[numsSize - 1];
	// free(retArray);

	// return retValue;

	int retValue = 0;

	int currentIndex = 0;
	int currentMax , i, nextIndex;
	while (currentIndex < (numsSize - 1))
	{
		retValue ++;

		currentMax = 0;
		nextIndex = currentIndex + 1;

		for (i = 1; i <= nums[currentIndex]; i++)
		{
			if ((currentIndex + i) >=  (numsSize - 1))
			{
				return retValue;
			}

			if ((nums[currentIndex + i] + currentIndex + i) > currentMax)
			{
				currentMax = nums[currentIndex + i] + currentIndex + i;
				nextIndex = currentIndex + i;
			}
		}
		currentIndex = nextIndex;
	}

	return retValue;
}

int main()
{
	return 0;
}