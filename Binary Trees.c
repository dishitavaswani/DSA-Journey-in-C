#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *right;
    struct node *left;
};

struct node *root = NULL;

struct node *insert(struct node *root, int n) {
struct node *temp=root;
struct node *new=(struct node *)malloc(sizeof(struct node));
new->data=n;
new->right=NULL;
new->left=NULL;
if(root==NULL)
{
    root=new;
    return root;
}
if(new->data < temp->data)
    temp->left=insert(temp->left,n);
else if(new->data > temp->data)
    temp->right=insert(temp->right,n);
else
{
    printf("Element already exists");
    free(new);
}
return root;

}

struct node *delete(struct node *root, int m)
{
    struct node *pt, *temp, *fp, *l;
    temp = root;
    pt = NULL;


    while (temp != NULL)
    {
        if (temp->data == m)
            break;
        else if (temp->data > m)
        {
            pt = temp;
            temp = temp->left;
        }
        else
        {
            pt = temp;
            temp = temp->right;
        }
    }


    if (temp == NULL)
    {
        printf("\nElement not found\n");
        return root;
    }

    if (temp->left == NULL && temp->right == NULL)
    {
        if (pt == NULL)
            return NULL;
        if (pt->left == temp)
            pt->left = NULL;
        else
            pt->right = NULL;
        free(temp);
    }

    else if (temp->left != NULL && temp->right == NULL)
    {
        if (pt == NULL)
            root = temp->left;
        else if (pt->left == temp)
            pt->left = temp->left;
        else
            pt->right = temp->left;
        free(temp);
    }

    else if (temp->left == NULL && temp->right != NULL)
    {
        if (pt == NULL)
            root = temp->right;
        else if (pt->left == temp)
            pt->left = temp->right;
        else
            pt->right = temp->right;
        free(temp);
    }

    else
    {
        struct node *succ = temp->right;
        struct node *succParent = temp;

        while (succ->left != NULL)
        {
            succParent = succ;
            succ = succ->left;
        }

        temp->data = succ->data;

        if (succParent->left == succ)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;

        free(succ);
    }

    return root;
}


void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}


void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

int main() {
    int ch, n, m;

    do {
        printf("\n1. Insert");
        printf("\n2. Delete ");
        printf("\n3. Inorder");
        printf("\n4. Preorder");
        printf("\n5. Postorder");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element to add: ");
                scanf("%d", &n);
                root = insert(root, n);
                break;

            case 2:
                if (root == NULL) {
                    printf("\nTree is empty\n");
                } else {
                    printf("Enter element to delete: ");
                    scanf("%d", &m);
                    root = delete(root, m);
                }
                break;

            case 3:
                if (root == NULL)
                    printf("\nTree is empty\n");
                else {
                    printf("Inorder Traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;

            case 4:
                if (root == NULL)
                    printf("\nTree is empty\n");
                else {
                    printf("Preorder Traversal: ");
                    preorder(root);
                    printf("\n");
                }
                break;

            case 5:
                if (root == NULL)
                    printf("\nTree is empty\n");
                else {
                    printf("Postorder Traversal: ");
                    postorder(root);
                    printf("\n");
                }
                break;

            case 6:
                printf("Exiting...\n");
                break;

        }

    } while (ch != 6);

    return 0;
}
