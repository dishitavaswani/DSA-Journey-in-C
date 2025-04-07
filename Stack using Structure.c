#include <stdio.h>
#define MAXSIZE 10

struct stack
{
 int arr[MAXSIZE];
 int top;
}s;

void Push();
void Pop();
void display();

void main()
  {
    int choice;
    s.top=-1;
    do
     {
        printf("--------STACK--------");
        printf("\n 1. Push \n 2. Pop \n 3. Display \n 4. Exit");
        printf("\n-----------------------");
        printf("\nEnter your Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: Push();
                    display();
                    break;
            case 2: Pop();
                    display();
                    break;
            case 3: display();
                    break;
            case 4: printf("Exiting the Program\n");
                    break;
            default: printf("Invalid Choice\n");
        }
    }
  while(choice != 4);
}

void Push() {
    int n;
    if (s.top == MAXSIZE - 1)
        printf("\nStack is Full\n");
    else {
        printf("Enter an Element: ");
        scanf("%d", &n);
        s.top++;
        s.arr[s.top] = n;
    }
}

void display() {
    int i;
    if (s.top == -1)
        printf("Stack is Empty\n");
    else {
        printf("Elements of Stack:");
        for(i =s.top; i >= 0; i--)
            printf("%d\n", s.arr[i]);
        printf("\n");
    }
}

void Pop() {
    int n;
    if(s.top == -1)
        printf("Stack is Empty\n");
    else {
        n = s.arr[s.top];
        s.top--;
        printf("Popped Element: %d\n", n);
    }
}
