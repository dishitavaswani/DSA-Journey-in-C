#include<stdio.h>
#include<stdlib.h>
struct Node
{
   int data;
   struct Node *next;
}*first=NULL;

void create(int A[],int n)
{
  int i;
  struct Node *t,*last;
  first=(struct Node *)malloc(sizeof(struct Node));
  first->data=A[0];
  first->next=NULL;
  last=first;

  for(i=1;i<n;i++)
  {
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=A[i];
    t->next=NULL;
    last->next=t;
    last=t;
  }
}
void Display(struct Node *p)
{
 while(p!=NULL)                //when i want to reverse use 'if' instead of 'while'
 {
    printf("%d\n",p->data);     //reverse the order of printf and display write it like display(p->next);
    p=p->next;
 }
}
int main()
{
  int A[]={3,5,7,10,15};
  create(A,5);
  Display(first);
  return 0;
}



