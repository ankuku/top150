#include <stdio.h>

int trap(int* height, int heightSize) {
    if (!height || heightSize < 3) {
        return 0;
    }

    int left = 0;
    int right = heightSize - 1;
    int leftMax = height[left];
    int rightMax = height[right];

    int trappedWater = 0;

    while (left < right) {
        if (leftMax < rightMax) {
            left++;
            leftMax = leftMax > height[left] ? leftMax : height[left];

            trappedWater += leftMax - height[left];
        }
        else {
            right--;
            rightMax = rightMax > height[right] ? rightMax : height[right];

            trappedWater += rightMax - height[right];
        }
    }

    
    return trappedWater;
}

int main() {
    int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int size = sizeof(height) / sizeof(height[0]);
    printf("%d\n", trap(height, size));
    return 0;
}