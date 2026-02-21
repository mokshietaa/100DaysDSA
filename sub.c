/*Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.
Input:
- First line: integer n
- Second line: n integers
Output:
- Print the count of subarrays having sum zero
Example:
Input:
6
1 -1 2 -2 3 -3
Output:
6
Explanation: A subarray is a continuous part of the array. For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6.*/
#include <stdio.h>
int countZeroSumSubarrays(int arr[], int n) {
    int count = 0;

    // Iterate through all possible subarrays
    for (int start = 0; start < n; start++) {
        int sum = 0;
        for (int end = start; end < n; end++) {
            sum += arr[end];
            if (sum == 0) {
                count++;
            }
        }
    }

    return count;
}
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = countZeroSumSubarrays(arr, n);
    printf("Count of subarrays with sum zero: %d\n", result);

    return 0;
}