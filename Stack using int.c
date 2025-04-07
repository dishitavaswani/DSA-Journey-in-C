#include <stdio.h>
#define MAXSIZE 10

int stack[MAXSIZE], top = -1;

void Push();
void Pop();
void display();

void main()
{
    int choice;
    do {
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
            default:
                printf("Invalid Choice\n");
        }
    }
    while(choice != 4);
}

void Push() {
    int n;
    if (top == MAXSIZE - 1)
        printf("\nStack is Full\n");
    else {
        printf("Enter an Element: ");
        scanf("%d", &n);
        top++;
        stack[top] = n;
    }
}

void display() {
    int i;
    if (top == -1)
        printf("Stack is Empty\n");
    else {
        printf("Elements of Stack:");
        for(i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
        printf("\n");
    }
}

void Pop() {
    int n;
    if(top == -1)
        printf("Stack is Empty\n");
    else {
        n = stack[top];
        top--;
        printf("Popped Element: %d\n", n);
    }
}
