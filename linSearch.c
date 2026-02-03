/*Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.
Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)
Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"
Example:
Input:
5
10 20 30 40 50
30
Output:
Found at index 2
Comparisons = 3
Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons)*/
#include <stdio.h>
int linearSearch(int arr[], int n, int k, int *comparisons) {
    for (int i = 0; i < n; i++) {
        (*comparisons)++;
        if (arr[i] == k) {
            printf("Found at index %d\n", i);
            return i;
        }
    }
    printf("Not Found\n");
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    int key = 30;
    int comparisons = 0;

    linearSearch(arr, n, key, &comparisons);

    printf("Total comparisons: %d\n", comparisons);
    return 0;
}

