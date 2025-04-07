#include <stdio.h>
#include <stdlib.h>

struct node
{

    int data;
    struct node *next;
};

struct node *insert(struct node *list, int value);
struct node *del(struct node *list, int target);
void display(struct node *list);

int main()
{
    struct node *myList;
    int choice, value;
    myList = NULL;

    do
    {
        printf("\nMenu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter the value to be inserted: ");
                scanf("%d", &value);
                myList = insert(myList, value);
                display(myList);
                break;

            case 2:
                printf("\nEnter the value to be deleted: ");
                scanf("%d", &value);
                myList = del(myList, value);
                display(myList);
                break;

            case 3:
                display(myList);
                break;

            case 4:
                printf("\nExiting the program\n");
                break;

            default:
                printf("\nInvalid Choice\n");
        }
    } while (choice != 4);

    return 0;
}

struct node *insert(struct node *list, int value)
{
    struct node *pnew, *hp;
    pnew = (struct node *)malloc(sizeof(struct node));
    pnew->data = value;
    pnew->next = NULL;

    if (list == NULL || list->data>value)
    {
        pnew->next= list;
        list = pnew;
        return list;
    }
    {
        hp = list;
        while (hp->next != NULL && hp->next->data < value)

            hp = hp->next;
            pnew->next = hp->next;

        hp->next = pnew;
        return list;
    }
}

struct node *del(struct node *list, int target)
{
    struct node *help_ptr, *node2delete;
    help_ptr = list;

    if (help_ptr != NULL)
    {
        if (help_ptr->data == target)
        {
            list = help_ptr->next;
            free(help_ptr);
            return list;
        }

        while (help_ptr->next != NULL)
        {
            if (help_ptr->next->data == target)
            {
                node2delete = help_ptr->next;
                help_ptr->next = help_ptr->next->next;
                free(node2delete);
                return list;
            }
            help_ptr = help_ptr->next;
        }

        printf("Element not found\n");
    }

    else
    {
        printf("List empty\n");
    }

    return list;
}

void display(struct node *list)
{
    if(list == NULL)
        {
        printf("list is empty\n");
        }

     while (list != NULL)
    {
        printf("%d\n", list->data);
        list = list->next;
    }

}

