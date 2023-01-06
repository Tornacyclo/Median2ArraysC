#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int totalSize = nums1Size + nums2Size;
    int* mergedNums = malloc(totalSize * sizeof(int));

    int i = 0, j = 0, k = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            mergedNums[k] = nums1[i];
            i++;
        } else {
            mergedNums[k] = nums2[j];
            j++;
        }
        k++;
    }

    while (i < nums1Size) {
        mergedNums[k] = nums1[i];
        i++;
        k++;
    }

    while (j < nums2Size) {
        mergedNums[k] = nums2[j];
        j++;
        k++;
    }

    double median;
    if (totalSize % 2 == 0) {
        median = (mergedNums[totalSize / 2 - 1] + mergedNums[totalSize / 2]) / 2.0;
    } else {
        median = mergedNums[totalSize / 2];
    }

    free(mergedNums);
    return median;
}
