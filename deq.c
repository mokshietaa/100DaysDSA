/*Problem: Deque (Double-Ended Queue)
A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.
Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.
Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.
Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)
Input:
- Sequence of deque operations with values (if applicable)
Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int arr[MAX];
    int front;
    int rear;
    int size;
} Deque;

void init(Deque *dq)
{
    dq->front = -1;
    dq->rear = -1;
    dq->size = 0;
}

int isEmpty(Deque *dq)
{
    return dq->size == 0;
}

int isFull(Deque *dq)
{
    return dq->size == MAX;
}

void push_front(Deque *dq, int value)
{
    if (isFull(dq))
        return;

    if (isEmpty(dq))
    {
        dq->front = dq->rear = 0;
    }
    else
    {
        dq->front = (dq->front - 1 + MAX) % MAX;
    }
    dq->arr[dq->front] = value;
    dq->size++;
}

void push_back(Deque *dq, int value)
{
    if (isFull(dq))
        return;

    if (isEmpty(dq))
    {
        dq->front = dq->rear = 0;
    }
    else
    {
        dq->rear = (dq->rear + 1) % MAX;
    }
    dq->arr[dq->rear] = value;
    dq->size++;
}

int pop_front(Deque *dq)
{
    if (isEmpty(dq))
        return -1;

    int val = dq->arr[dq->front];
    if (dq->size == 1)
    {
        dq->front = dq->rear = -1;
    }
    else
    {
        dq->front = (dq->front + 1) % MAX;
    }
    dq->size--;
    return val;
}

int pop_back(Deque *dq)
{
    if (isEmpty(dq))
        return -1;

    int val = dq->arr[dq->rear];
    if (dq->size == 1)
    {
        dq->front = dq->rear = -1;
    }
    else
    {
        dq->rear = (dq->rear - 1 + MAX) % MAX;
    }
    dq->size--;
    return val;
}

int front(Deque *dq)
{
    if (isEmpty(dq))
        return -1;
    return dq->arr[dq->front];
}

int back(Deque *dq)
{
    if (isEmpty(dq))
        return -1;
    return dq->arr[dq->rear];
}

int size(Deque *dq)
{
    return dq->size;
}

void clear(Deque *dq)
{
    dq->front = dq->rear = -1;
    dq->size = 0;
}
void assign(Deque *dq, int arr[], int n)
{
    clear(dq);
    for (int i = 0; i < n; i++)
    {
        push_back(dq, arr[i]);
    }
}
void reverse(Deque *dq)
{
    int i = dq->front, j = dq->rear;
    while (i != j && (i + MAX - 1) % MAX != j)
    {
        int temp = dq->arr[i];
        dq->arr[i] = dq->arr[j];
        dq->arr[j] = temp;

        i = (i + 1) % MAX;
        j = (j - 1 + MAX) % MAX;
    }
}
void sort(Deque *dq)
{
    for (int i = 0; i < dq->size - 1; i++)
    {
        for (int j = 0; j < dq->size - i - 1; j++)
        {
            int idx1 = (dq->front + j) % MAX;
            int idx2 = (dq->front + j + 1) % MAX;

            if (dq->arr[idx1] > dq->arr[idx2])
            {
                int temp = dq->arr[idx1];
                dq->arr[idx1] = dq->arr[idx2];
                dq->arr[idx2] = temp;
            }
        }
    }
}
void display(Deque *dq)
{
    if (isEmpty(dq))
        return;
    int i = dq->front;
    for (int count = 0; count < dq->size; count++)
    {
        printf("%d ", dq->arr[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}
int main()
{
    Deque dq;
    init(&dq);
    push_back(&dq, 3);
    push_front(&dq, 1);
    push_back(&dq, 2);
    printf("%d\n", front(&dq));
    printf("%d\n", back(&dq));
    printf("%d\n", size(&dq));
    sort(&dq);
    display(&dq);
    reverse(&dq);
    display(&dq);
    return 0;
}