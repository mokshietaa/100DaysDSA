/*Problem: Given an array of integers, find two elements whose sum is closest to zero.
Input:
- First line: integer n
- Second line: n space-separated integers
Output:
- Print the pair of elements whose sum is closest to zero
Example:
Input:
5
1 60 -10 70 -80
Output:
-10 1
Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.*/
#include <stdio.h>
#include <stdlib.h>

void findClosestPair(int arr[], int n) {
    // sort array
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int left = 0;
    int right = n - 1;

    int min_sum = arr[left] + arr[right];
    int num1 = arr[left], num2 = arr[right];

    while(left < right) {
        int sum = arr[left] + arr[right];

        if(abs(sum) < abs(min_sum)) {
            min_sum = sum;
            num1 = arr[left];
            num2 = arr[right];
        }

        if(sum < 0)
            left++;   // need bigger sum
        else
            right--;  // need smaller sum
    }

    printf("%d %d", num1, num2);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    findClosestPair(arr, n);
    return 0;
}