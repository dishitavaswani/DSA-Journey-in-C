#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
 int data;
 struct Node *left, *right;
} Node;
Node* createNode(int data) {
 Node* newNode = (Node*)malloc(sizeof(Node));
 newNode->data = data;
 newNode->left = newNode->right = NULL;
 return newNode;
}
Node* insert(Node* root, int data) {
 if (root == NULL)
 return createNode(data);
 if (data < root->data)
 root->left = insert(root->left, data);
 else if (data > root->data)
 root->right = insert(root->right, data);
 return root;
}
Node* findMinNode(Node* node) {
 Node* current = node;
 while (current && current->left != NULL)
 current = current->left;
 return current;
}
Node* deleteNode(Node* root, int key) {
 if (root == NULL)
 return root;
 if (key < root->data)
 root->left = deleteNode(root->left, key);
 else if (key > root->data)
 root->right = deleteNode(root->right, key);
 else {
 if (root->left == NULL) {
 Node* temp = root->right;
 free(root);
 return temp;
 } else if (root->right == NULL) {
 Node* temp = root->left;
 free(root);
 return temp;
 }
 Node* temp = findMinNode(root->right);
 root->data = temp->data;
 root->right = deleteNode(root->right, temp->data);
 }
 return root;
}
int countLeafNodes(Node* root) {
 if (root == NULL)
 return 0;
 if (root->left == NULL && root->right == NULL)
 return 1;
 return countLeafNodes(root->left) + countLeafNodes(root->right);
}
int findMin(Node* root) {
Node* current = root;
 while (current && current->left != NULL)
 current = current->left;
 return current->data;
}
int findMax(Node* root) {
 Node* current = root;
 while (current && current->right != NULL)
 current = current->right;
 return current->data;
}
int findHeight(Node* root) {
 if (root == NULL)
 return -1;
 int leftHeight = findHeight(root->left);
 int rightHeight = findHeight(root->right);
 return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
void inorder(Node* root) {
 if (root != NULL) {
 inorder(root->left);
 printf("%d ", root->data);
 inorder(root->right);
 }
}
void preorder(Node* root) {
 if (root != NULL) {
 printf("%d ", root->data);
 preorder(root->left);
 preorder(root->right);
 }
}
void postorder(Node* root) {
 if (root != NULL) {
 postorder(root->left);
 postorder(root->right);
 printf("%d ", root->data);
  }
}
void displayMenu() {
 printf("\n Binary Search Tree Operations \n");
 printf("1. Insert\n");
 printf("2. Delete\n");
 printf("3. Count Leaf Nodes\n");
 printf("4. Find Minimum Value\n");
 printf("5. Find Maximum Value\n");
 printf("6. Find Height of Tree\n");
 printf("7. Inorder Traversal\n");
 printf("8. Preorder Traversal\n");
 printf("9. Postorder Traversal\n");
 printf("10. Exit\n");
 printf("Enter your choice: ");
}
void main() {
 Node* root = NULL;
 int choice, value;
 do {
 displayMenu();
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter value to insert: ");
 scanf("%d", &value);
 root = insert(root, value);
 break;
 case 2:
 printf("Enter value to delete: ");
 scanf("%d", &value);
 root = deleteNode(root, value);
 break;
 case 3:
 printf("Number of leaf nodes: %d\n", countLeafNodes(root));
 break;
 case 4:
 if (root != NULL)
 printf("Minimum value: %d\n", findMin(root));
 else
 printf("Tree is empty.\n");
 break;
 case 5:
 if (root != NULL)
 printf("Maximum value: %d\n", findMax(root));
 else
 printf("Tree is empty.\n");
 break;
 case 6:
 printf("Height of the tree: %d\n", findHeight(root));
 break;
 case 7:
 printf("Inorder Traversal: ");
 inorder(root);
 printf("\n");
 break;
 case 8:
 printf("Preorder Traversal: ");
 preorder(root);
 printf("\n");
 break;
 case 9:
 printf("Postorder Traversal: ");
 postorder(root);
 printf("\n");
 break;
 case 10:
 printf("Exiting program.\n");
 break;
 default:
 printf("Invalid choice! Please enter a number between 1 and 10.\n");
 }
 } while (choice != 10);
}
