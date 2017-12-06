#include <stdio.h>

int trap(int* height, int heightSize) {
    int left_max, right_max, left, right;
    int count = 0;

    left_max = 0;
    right_max = 0;
    left = 0, right = heightSize - 1;

    while(left < right) {
        if(height[left] < height[right]) {
            if(height[left] < left_max) {
                count += left_max - height[left];
            } else {
                left_max = height[left];
            }

            left++;
        } else {
            if(height[right] < right_max) {
                count += right_max - height[right];
            } else {
                right_max = height[right];
            }

            right--;
        }
    }

    return count;
}

int main()
{
    return 0;
}