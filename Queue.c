#include <stdio.h>

struct QueueType
{
    int x[4];
    int front, rear, size;
} queue;

void main()
 {
    queue.front = -1;
    queue.rear = -1;
    queue.size = 0;
    int choice, value;
    do
     {
        printf("\n\nQueue Operations Menu:");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
         {
            case 1:
                printf("Enter the value to insert into the queue: ");
                scanf("%d", &value);
                enqueue(value);
                display();
                break;
            case 2:
                dequeue();
                display();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program...");
                break;
            default:
                printf("\nInvalid choice. Please try again.");
        }
    }
    while (choice != 4);
}


void enqueue(int value) {
    if (queue.rear == 5) {
        printf("\nQueue is full! Cannot insert %d.", value);
    } else {
        if (queue.front == -1)
            queue.front = 0;
        queue.rear++;
        queue.x[queue.rear] = value;
        queue.size++;
        printf("\nInserted element: %d", value);
    }
}

void dequeue() {
    if (queue.front == -1 || queue.front > queue.rear) {
        printf("\nQueue is empty! Cannot delete.");
    } else {
        printf("\nDeleted element: %d", queue.x[queue.front]);
        queue.front++;
        queue.size--;
        if (queue.front > queue.rear)
            queue.front = queue.rear = -1;
    }
}

void display() {
    if (queue.front == -1) {
        printf("\nQueue is empty!");
    } else {
        printf("\nCurrent queue elements: ");
        for (int i = queue.front; i <= queue.rear; i++)
            printf("%d ", queue.x[i]);
    }
}

