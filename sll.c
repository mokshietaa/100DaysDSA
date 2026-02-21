/*Problem: Create and Traverse Singly Linked List
Input:
- First line: integer n
- Second line: n space-separated integers
Output:
- Print the result
Example:
Input:
5
10 20 30 40 50
Output:
10 20 30 40 50*/
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    struct node* head = NULL;
    struct node* temp = NULL;
    for (int i = 0; i < n; i++) {
        int value;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        struct node* new_node;
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = value;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            temp = head;
        } else {
            temp->next = new_node;
            temp = temp->next;
        }
    }
    printf("Linked List: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}
