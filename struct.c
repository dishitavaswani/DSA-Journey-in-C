#include<stdio.h>
struct rectangle
{
  int length;
  int breadth;
  int area;
}r;


int main()
{
  r.length=15;
  r.breadth=10;
  printf("area of reactangle=%d",r.length*r.breadth);
}
