#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);  // Use &n to correctly store the input

    int a[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter a number: ");
        scanf("%d", &a[i]);  // Use &a[i] to correctly store the input
    }

    printf("\nYou entered:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
    return 0;
}
