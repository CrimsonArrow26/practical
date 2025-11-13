#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

// Function to create new node
struct node* createNode(int value) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
struct node* insert(struct node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Function to search a value in BST
void search(struct node* root, int key) {
    if (root == NULL) {
        printf("\nValue %d not found in tree.", key);
        return;
    }
    if (root->data == key)
        printf("\nValue %d found in tree!", key);
    else if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

// Function to find minimum value
int minValue(struct node* root) {
    struct node* current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current->data;
}

// Function to find height (longest path)
int height(struct node* root) {
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

// Function to create mirror of tree
void mirror(struct node* root) {
    struct node* temp;
    if (root == NULL)
        return;
    mirror(root->left);
    mirror(root->right);

    // Swap left and right pointers
    temp = root->left;
    root->left = root->right;
    root->right = temp;
}

// Inorder traversal (to display sorted tree)
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function
void main() {
    struct node* root = NULL;
    int choice, value;
    clrscr();

    do {
        printf("\n\n====== BINARY SEARCH TREE MENU ======");
        printf("\n1. Insert Node");
        printf("\n2. Display (Inorder Traversal)");
        printf("\n3. Find Number of Nodes in Longest Path (Height)");
        printf("\n4. Find Minimum Data Value");
        printf("\n5. Mirror the Tree");
        printf("\n6. Search a Value");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("\nInorder Traversal (sorted order): ");
                inorder(root);
                break;

            case 3:
                printf("\nHeight of tree = %d", height(root));
                break;

            case 4:
                if (root != NULL)
                    printf("\nMinimum value in tree = %d", minValue(root));
                else
                    printf("\nTree is empty!");
                break;

            case 5:
                mirror(root);
                printf("\nTree mirrored successfully!");
                break;

            case 6:
                printf("\nEnter value to search: ");
                scanf("%d", &value);
                search(root, value);
                break;

            case 7:
                printf("\nExiting...");
                break;

            default:
                printf("\nInvalid choice!");
        }
    } while (choice != 7);

    getch();
}
