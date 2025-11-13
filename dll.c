/* Doubly Linked List: Create, Add, Display (forward)
   Turbo C / Borland C compatible */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
};

struct DNode *headD = NULL;

/* Create first node */
void createD(int value) {
    struct DNode *temp; /* declarations at top */

    if (headD != NULL) {
        printf("List already created.\n");
        return;
    }

    temp = (struct DNode*)malloc(sizeof(struct DNode));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    temp->data = value;
    temp->prev = NULL;
    temp->next = NULL;
    headD = temp;
}

/* Add node at end */
void addNodeD(int value) {
    struct DNode *newNode;
    struct DNode *temp;

    newNode = (struct DNode*)malloc(sizeof(struct DNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (headD == NULL) {
        headD = newNode;
        return;
    }

    temp = headD;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

/* Display forward */
void displayListD() {
    struct DNode *temp;

    temp = headD;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void main() {
    int choice, value;
    clrscr();

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Create (first node)\n");
        printf("2. Add (at end)\n");
        printf("3. Display (forward)\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            createD(value);
        }
        else if (choice == 2) {
            printf("Enter value: ");
            scanf("%d", &value);
            addNodeD(value);
        }
        else if (choice == 3) {
            displayListD();
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
