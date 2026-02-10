/*Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.
Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)
Output:
- Print the transformed code name after applying the mirror operation
Example:
Input:
hello
Output:
olleh
Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored*/
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100
int main() {
    char codeName[MAX_LENGTH];
    printf("Enter the code name: ");
    scanf("%s", codeName);
    int length = strlen(codeName); 
    char mirroredCodeName[MAX_LENGTH];
    for (int i = 0; i < length; i++) {
        mirroredCodeName[i] = codeName[length - 1 - i];
    }
    mirroredCodeName[length] = '\0';
    printf("Mirrored code name: %s\n", mirroredCodeName);
    
    return 0;
}