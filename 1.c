#include <stdio.h>
#include <stdlib.h>

// 1. Two Sum

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int i, j, flag;
    int *retNums = (int *)malloc(2 * sizeof(int));
    
    flag = 0;
    for(i = 0; i < numsSize; i++) {
        for(j = i + 1; j < numsSize; j++) {
            if(nums[i] + nums[j] == target) {
                retNums[0] = i;
                retNums[1] = j;
                
                flag = 1;
                break;
            }
        }
        
        if(flag == 1) {
            break;
        }
    }
    
    return retNums;
}

int main()
{
    return 0;
}