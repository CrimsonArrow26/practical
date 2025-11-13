#include <stdio.h>
#include <conio.h>
#define MAX 5     // maximum number of orders

int queue[MAX];
int front = -1, rear = -1;

// Function to add order
void addOrder() {
    int order;
    if ((rear + 1) % MAX == front) {
        printf("\nSorry! Orders are full. Please wait.");
        return;
    }

    printf("\nEnter order number: ");
    scanf("%d", &order);

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = order;

    printf("\nOrder %d added successfully!", order);
}

// Function to serve order
void serveOrder() {
    int order;
    if (front == -1) {
        printf("\nNo orders to serve!");
        return;
    }

    order = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;

    printf("\nOrder %d served successfully!", order);
}

// Function to display current orders
void displayOrders() {
    int i;
    if (front == -1) {
        printf("\nNo pending orders!");
        return;
    }

    printf("\nPending Orders:\n");
    i = front;
    while (1) {
        printf("Order %d\n", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
}

// Main function
void main() {
    int choice;
    clrscr();

    do {
        printf("\n\n====== PIZZA PARLOUR MANAGEMENT ======");
        printf("\n1. Add Order");
        printf("\n2. Serve Order");
        printf("\n3. Display Orders");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addOrder(); break;
            case 2: serveOrder(); break;
            case 3: displayOrders(); break;
            case 4: printf("\nThank you! Visit again."); break;
            default: printf("\nInvalid choice!");
        }
    } while (choice != 4);

    getch();
}
