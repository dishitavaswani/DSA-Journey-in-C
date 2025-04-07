#include <stdio.h>
#define MAXSIZE 10

struct queue
{
    int arr[MAXSIZE];
    int front, rear;
} q;

void Enqueue();
void Dequeue();
void display();

void main()
{
    int choice;
    q.front = 0;
    q.rear = -1;
    do
    {
        printf("--------QUEUE--------");
        printf("\n 1. Enqueue \n 2. Dequeue \n 3. Display \n 4. Exit");
        printf("\n---------------------");
        printf("\nEnter your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Enqueue();
            display();
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting the Program\n");
            break;
        default:
            printf("Invalid Choice\n");
        }
    } while (choice != 4);
}

void Enqueue()
{
    int n;
    if (q.rear == MAXSIZE - 1)
        printf("\nQueue is Full\n");
    else
    {
        printf("Enter an Element: ");
        scanf("%d", &n);
        q.rear++;
        q.arr[q.rear] = n;
    }
}

void Dequeue()
{
int n;
    if (q.front > q.rear)

        printf("Queue is Empty\n");

    else
    {
        n=q.arr[q.front];
        printf("Dequeued Element: %d\n",n);
        q.front++;
    }
}

void display()
{
    int i;
    if (q.front > q.rear)
        printf("Queue is Empty\n");
    else
    {
        printf("Elements of Queue:");
        for (i = q.rear; i >= q.front; i--)
            printf("%d\n", q.arr[i]);
        printf("\n");
    }
}
