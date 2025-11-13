/* Singly Linked List: Create, Add, Display
   Turbo C / Borland C compatible */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

/* Create first node */
void create(int value) {
    struct Node *temp; /* declarations at top */

    if (head != NULL) {
        printf("List already created.\n");
        return;
    }

    temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    temp->data = value;
    temp->next = NULL;
    head = temp;
}

/* Add node at end */
void addNode(int value) {
    struct Node *newNode;
    struct Node *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

/* Display list */
void displayList() {
    struct Node *temp;

    temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void main() {
    int choice, value;
    clrscr();

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Create (first node)\n");
        printf("2. Add (at end)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            create(value);
        }
        else if (choice == 2) {
            printf("Enter value: ");
            scanf("%d", &value);
            addNode(value);
        }
        else if (choice == 3) {
            displayList();
        }
        else if (choice == 4) {
            printf("Exiting...\n");
            getch();
            exit(0);
        }
        else {
            printf("Invalid choice.\n");
        }
    }

    getch();
}
