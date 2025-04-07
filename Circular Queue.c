#include <stdio.h>
#define MAXSIZE 3
struct cirqueue
{
  int arr[MAXSIZE];
  int front, rear;
}q;
void Enqueue();
void Dequeue();
void display();

void main()
{
    int choice;
    q.front = -1; // Initialize front to -1
    q.rear = -1;  // Initialize rear to -1
    do
    {
        printf("--------CIRCULAR QUEUE--------");
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
  if((q.rear + 1) % MAXSIZE == q.front)
  printf("\nQueue is full\n");
  else
  {
    printf("Enter an element: ");
    scanf("%d",&n);
   if (q.rear == -1 && q.front == -1)
   {
    q.rear =0;
    q.front =0;
   }
  else
  {
   q.rear= (q.rear + 1) % MAXSIZE;
  }
  q.arr[q.rear] = n;
 }
}
void Dequeue()
{
 int n;
    if (q.front == -1 && q.rear == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        n = q.arr[q.front];
        if (q.front == q.rear)
        {
          q.front = -1;
          q.rear = -1;
        }
        else
        {
        q.front = (q.front + 1) % MAXSIZE;
          printf("deleted element is %d\n",n);
        }
    }
}
void display()
{
    int i;
  if (q.rear == -1 && q.front ==  -1)

  {
   printf("Queue is empty\n");
  }
  else
  {
    printf("Queue Elements:");
    i = q.front;
    do{
        printf("%d->", q.arr[i]);
        i = (i+1) % MAXSIZE;
    }while (i != ((q.rear + 1) % MAXSIZE));
    printf("\n");
  }
}
