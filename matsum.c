/*Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

Input:
- First line: two integers m and n
- Next m lines: n integers each

Output:
- Print the sum of the primary diagonal elements

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
15

Explanation:
1 + 5 + 9 = 15*/
#include <stdio.h>
#define MAX_SIZE 100
int main() {
    int m, n;
    int matrix[MAX_SIZE][MAX_SIZE];
    // Read the dimensions of the matrix
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);
    // Read the matrix elements
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    // Calculate the sum of the primary diagonal elements
    int sum = 0;
    for (int i = 0; i < m && i < n; i++) {
        sum += matrix[i][i];
    }
    // Print the result
    printf("Sum of primary diagonal elements: %d\n", sum);
    return 0;
}
