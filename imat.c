/*Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

Input:
- First line: integer n representing number of rows and columns
- Next n lines: n integers each representing the matrix elements

Output:
- Print "Identity Matrix" if the matrix satisfies the condition
- Otherwise, print "Not an Identity Matrix"

Example:
Input:
3
1 0 0
0 1 0
0 0 1

Output:
Identity Matrix*/
#include <stdio.h>
#define MAX_SIZE 100
int main() {
    int n;
    int matrix[MAX_SIZE][MAX_SIZE];
    // Read the dimension of the matrix
    printf("Enter the number of rows and columns: ");
    scanf("%d", &n);
    // Read the matrix elements
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    // Check if the matrix is an identity matrix
    int isIdentity = 1; // Assume it is an identity matrix until proven otherwise
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == j && matrix[i][j] != 1) || (i != j && matrix[i][j] != 0)) {
                isIdentity = 0; // Not an identity matrix
                break;
            }
        }
        if (!isIdentity) {
            break;
        }
    }
    // Print the result
    if (isIdentity) {
        printf("Identity Matrix\n");
    } else {
        printf("Not an Identity Matrix\n");
    }
    return 0;
}