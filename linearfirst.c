#include <stdio.h>
#include <conio.h>

void main() {
    int roll[50], n, i, search, found = 0;

    clrscr();
    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter roll numbers:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &roll[i]);

    printf("Enter roll number to search: ");
    scanf("%d", &search);

    for(i = 0; i < n; i++) {
        if(roll[i] == search) {
            found = 1;
            break;
        }
    }

    if(found == 1)
        printf("Student attended the training program.\n");
    else
        printf("Student did not attend the training program.\n");

    getch();
}
