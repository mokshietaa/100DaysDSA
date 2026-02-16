/*Problem: Given an array of integers, count the frequency of each distinct element and print the result.

Input:
- First line: integer n (size of array)
- Second line: n integers

Output:
- Print each element followed by its frequency in the format element:count

Example:
Input:
5
1 2 2 3 1

Output:
1:2 2:2 3:1*/
#include <stdio.h>
#define MAX_SIZE 100
int main() {
    int n;
    int arr[MAX_SIZE];
    // Read the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    // Read the array elements
    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // Count the frequency of each distinct element
    int frequency[MAX_SIZE] = {0}; // Initialize frequency array to 0
    for (int i = 0; i < n; i++) {
        frequency[arr[i]]++;
    }
    // Print each element followed by its frequency
    printf("Element:Frequency\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (frequency[i] > 0) {
            printf("%d:%d ", i, frequency[i]);
        }
    }
    printf("\n");
    return 0;
}