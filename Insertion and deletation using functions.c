#include <stdio.h>

int array[20], currentSize;

void insertElement(int position, int value);
void removeElement();
void showArray();

void main() {
    int choice;
    printf("Enter array size: ");
    scanf("%d", &currentSize);
    if (currentSize > 20)
        printf("\nArray Overflow\n");
    else {
        printf("\nEnter elements of the array:\n");
        for (int i = 0; i < currentSize; i++) {
            scanf("%d", &array[i]);
        }
    }
    do {
        printf("\nOptions:\n1. Insert\n2. Remove\n3. Display\n4. Exit\nSelect: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int position, value;
                printf("Enter position to insert: ");
                scanf("%d", &position);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertElement(position, value);
                showArray();
                break;
            }
            case 2: removeElement();
                    showArray();
                    break;
            case 3: showArray();
                    break;
            case 4: printf("\nExiting the program...\n");
                    break;
            default: printf("\nInvalid selection\n");
        }
    } while (choice != 4);
}

void insertElement(int position, int value) {
    if (position <= 0 || position > currentSize + 1) {
        printf("\nInvalid position\n");
        return;
    }
    if (currentSize >= 20) {
        printf("\nArray is full (OVERFLOW)\n");
        return;
    }
    for (int i = currentSize - 1; i >= position - 1; i--) {
        array[i + 1] = array[i];
    }
    array[position - 1] = value;
    currentSize++;
}

void removeElement() {
    int position;
    printf("Enter position to delete: ");
    scanf("%d", &position);
    if (position <= 0 || position > currentSize) {
        printf("Invalid position\n");
    } else {
        for (int i = position - 1; i < currentSize - 1; i++) {
            array[i] = array[i + 1];
        }
        currentSize--;
        printf("Element deleted\n");
    }
}

void showArray() {
    if (currentSize == 0)
        printf("The array is empty\n");
    else {
        printf("Array elements are:\n");
        for (int i = 0; i < currentSize; i++) {
            printf("%d\n", array[i]);
        }
    }
}
