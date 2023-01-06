#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>



double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int low = 0, high = nums1Size;
    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (nums1Size + nums2Size + 1) / 2 - partitionX;

        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == nums1Size) ? INT_MAX : nums1[partitionX];

        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == nums2Size) ? INT_MAX : nums2[partitionY];

        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if ((nums1Size + nums2Size) % 2 == 0) {
                return (double)(fmax(maxLeftX, maxLeftY) + fmin(minRightX, minRightY)) / 2;
            } else {
                return (double)fmax(maxLeftX, maxLeftY);
            }
        } else if (maxLeftX > minRightY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }

    return 0;
}

int main(){
    
    
    int nums1[] = {1, 3, 5, 7};
    int nums2[] = {2, 4, 6, 8};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
    
    int nums3[] = {1, 2, 3, 4};
    int nums4[] = {5, 6, 7, 8, 9, 10};
    int nums3Size = sizeof(nums3) / sizeof(nums3[0]);
    int nums4Size = sizeof(nums4) / sizeof(nums4[0]);
    
    
    
    double median1 = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
    printf("The median is: %f\n", median1);
    
    
    double median2 = findMedianSortedArrays(nums3, nums3Size, nums4, nums4Size);
    printf("The median is: %f\n", median2);
    
    
    return 0;
    
    

}
