/*Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3*/
#include <stdio.h>
void rotate(int arr[], int n, int k) {
    k = k % n; // Handle cases where k is greater than n
    int temp[n];

    // Copy the last k elements to the beginning of temp
    for (int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    // Copy the first n-k elements to the end of temp
    for (int i = 0; i < n - k; i++) {
        temp[k + i] = arr[i];
    }

    // Copy the rotated array back to arr
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
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

    int k;
    printf("Enter the number of positions to rotate: ");
    scanf("%d", &k);

    rotate(arr, n, k);

    printf("Rotated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}