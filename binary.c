#include <stdio.h>
#include <conio.h>

void main() {
    int roll[50], n, i, search;
    int low, high, mid, found = 0;

    clrscr();

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter roll numbers in sorted order:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &roll[i]);

    printf("Enter roll number to search: ");
    scanf("%d", &search);

    low = 0;
    high = n - 1;

    while(low <= high) {
        mid = (low + high) / 2;

        if(roll[mid] == search) {
            found = 1;
            break;
        }
        else if(search < roll[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if(found == 1)
        printf("Student attended the training program.\n");
    else
        printf("Student did not attend the training program.\n");

    getch();
}
