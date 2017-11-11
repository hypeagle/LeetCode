#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 16. 3Sum Closest

int threeSumClosest(int* nums, int numsSize, int target) {
    int retInt = 0;
    int index, tmp;
	int i, j, k;
	int left, right;

    if(numsSize == 0) {
        return 0;
    } else if(numsSize == 1) {
        return nums[0];
    } else if(numsSize == 2) {
        return nums[0] + nums[1];
    }

    retInt = nums[0] + nums[1] + nums[2];
    for(i = 0; i < numsSize; i++) {
        for (j = i + 1; j < numsSize; j++) {
            for(k = j + 1; k < numsSize; k++) {
                tmp = nums[i] + nums[j] + nums[k];
                if(abs(retInt - target) > abs(tmp - target)) {
                    retInt = tmp;
                }
            }
        }
    }

    return retInt;

    // for (i = 0; i < numsSize; i++)
	// {
	// 	for (j = i + 1; j < numsSize; j++)
	// 	{
	// 		if (nums[i] > nums[j])
	// 		{
	// 			index = nums[i];
	// 			nums[i] = nums[j];
	// 			nums[j] = index;
	// 		}
	// 	}
	// }
}

int main()
{
    return 0;
}