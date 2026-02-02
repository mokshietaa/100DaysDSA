/*Delete an Element from an Array
Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. 
Shift remaining elements to the left.
Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)
Output:
- Print the updated array with (n-1) elements, space-separated
Example:
Input:
5
10 20 30 40 50
2
Output:
10 30 40 50
Explanation: Delete position 2 (element 20), remaining elements shift left*/
#include<stdio.h>
int main(){
    int arr[10], n, i, x, index, pos;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(i=0; i<n; i++){
        scanf("%d", arr+i);
    }
    printf("Enter position you want to delete the element at: ");
    scanf("%d", &pos);
    index=pos-1;
    printf("Enter the element you want to delete: ");
    scanf("%d", &x);
    for(i=index; i<n-1; i++){
        arr[i] = arr[i+1];
    }
    printf("Updated array: ");
    for(i = 0; i < n-1; i++){
        printf("%d ", arr[i]);
    } 
    return 0;
}