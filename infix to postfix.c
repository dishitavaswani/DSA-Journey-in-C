#include<stdio.h>
#include<ctype.h>

#define MAXSIZE 50

char s[MAXSIZE];
int top=-1;

void push(char elem); //pushes elem into the stack
char pop();
int pr(char elem); //returns the value of precedence of the elem
void infixtopostfix();

void push(char elem)
{
  s[++top]=elem;
}
char pop()
{
  return (s[top--]);
}
int pr(char elem)
{
 switch (elem)
 {
   case '#': return 0;
   case '(': return 1;
   case '+':
   case '-': return 2;
   case '*':
   case '/': return 3;
   case '^': return 4;
   default: return -1;
 }
}
void infixtopostfix()
{
 char infix[MAXSIZE], postfix[MAXSIZE], ch, elem;
 int i = 0, k = 0;

 printf("Enter an infix expression: ");
 scanf("%s", infix);

 push('#'); //sentinel char: remarks the end of the data structure

 while((ch = infix[i++]) != '\0') //while loop continues till the end of the string

 {
   if(isalnum(ch)) //isalnum is to check if ch is an alphanumeric character
   {
     postfix[k++] = ch;
   }
   else if (ch=='(')
   {
    push(ch);  //only '(' needs to be pushed in the stack
   }
   else if (ch == ')')
   {
     while (s[top] != '(')   //pops elements from the stack and adds them to the postfix expression
        postfix[k++] = pop();
     pop();
   }
   else
   {
     while (pr(s[top]) >= pr(ch) && ch != '^')  //Pops elements from the stack and adds them to the postfix expression while the precedence of the top element of the stack is greater than or equal to the precedence of ch.
         postfix[k++] = pop();
     push(ch);
   }
 }
 while (s[top] != '#') //after the expression ends..it pops out the remaining elements until '#'
    postfix[k++] = pop(); //adds popped elements to postfix exp
 postfix[k] = '\0';

 printf("\n Given Infix Expression: %s\nPostfix Expression: %s\n", infix, postfix);
}
int main()
{
 int choice;

 do
 {
   printf("\nMenu\n");
   printf("1. Convert Infix to Postfix:\n");
   printf("2. Exit\n");
   printf("Enter your choice: ");
   scanf("%d", &choice);
   switch (choice)
   {
     case 1:
        infixtopostfix();
        break;
     case 2:
        printf("EXIT..\n");
        return 0;
      default:
        printf("Invalid Choice!");
   }
 }while(choice != 2);

 return 0;
}
