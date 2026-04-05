/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int pq[MAX];
int size = 0;

void insert(int x)
{
    int i = size++;
    pq[i] = x;

    while (i > 0 && pq[(i - 1) / 2] > pq[i])
    {
        int temp = pq[i];
        pq[i] = pq[(i - 1) / 2];
        pq[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void heapify(int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && pq[left] < pq[smallest])
        smallest = left;

    if (right < size && pq[right] < pq[smallest])
        smallest = right;

    if (smallest != i)
    {
        int temp = pq[i];
        pq[i] = pq[smallest];
        pq[smallest] = temp;
        heapify(smallest);
    }
}

int deleteMin()
{
    if (size == 0)
        return -1;

    int root = pq[0];
    pq[0] = pq[--size];
    heapify(0);
    return root;
}

int peek()
{
    if (size == 0)
        return -1;
    return pq[0];
}

int main()
{
    int n;
    scanf("%d", &n);

    while (n--)
    {
        char op[10];
        scanf("%s", op);

        if (op[0] == 'i')
        {
            int x;
            scanf("%d", &x);
            insert(x);
        }
        else if (op[0] == 'd')
        {
            printf("%d\n", deleteMin());
        }
        else if (op[0] == 'p')
        {
            printf("%d\n", peek());
        }
    }

    return 0;
}