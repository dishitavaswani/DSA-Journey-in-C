#include<stdio.h>
#define MAXSIZE 5
int Queue[MAXSIZE];
int front = 0;
int rear = -1;

void Insert();
void Delete();
void Display();

void main()
{
 int choice;
 do
 {
   printf("-------Menu-------");
   printf("\n 1.Insert \n 2.Delete \n 3.Display \n 4.Exit\n ");
   printf("\n-------------------\n");
   printf("Enter your choice:");
   scanf("%d",&choice);
   switch(choice)
   {
    case 1:Insert();
           Display();
           break;
    case 2: Delete();
            Display();
            break;
    case 3: Display();
            break;
    case 4: printf("Exiting The Program");
            break;
    default:
            printf("Invalid Choice\n");

    }
  }while (choice!=4);
}
void Insert()
{
    int n;
    if (rear == MAXSIZE-1)
        printf("\n Queue is full\n");
    else
    {
        printf("Enter an Element:");
        scanf("%d",&n);
        rear++;
        Queue[rear]= n;
    }
}
void Delete()
{
    int n;
    if (front>rear)
        printf("Queue is Empty");
    else
    {
        n= Queue[front];
        printf("Deleted Element: %d",n);
        front++;
    }
}
void  Display()
{
    int i;
    if (front>rear)
        printf("Queue is Empty");
    else
    {
        printf("Elements of Queue:");
        for(i= rear; i>= front; i--)
        printf("%d\n",Queue[i]);
    }
}
