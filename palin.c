/*Problem: Read a string and check if it is a palindrome using two-pointer comparison.
Input:
- Single line: string s
Output:
- Print YES if palindrome, otherwise NO
Example:
Input:
level
Output:
YES
Explanation: String reads same forwards and backwards*/
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100
int main() {
    char s[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", s);
    int left = 0;
    int right = strlen(s) - 1;
    int isPalindrome = 1; 
    while (left < right) {
        if (s[left] != s[right]) {
            isPalindrome = 0; 
            break;
        }
        left++;
        right--;
    }
    if (isPalindrome) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}