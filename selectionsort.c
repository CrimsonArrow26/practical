#include <stdio.h>
#include <conio.h>

void selectionSort(float arr[], int n) {
    int i, j, min;
    float temp;
    for(i = 0; i < n-1; i++) {
        min = i;
        for(j = i+1; j < n; j++) {
            if(arr[j] < arr[min])
                min = j;
        }
        // Swap
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void main() {
    float percent[50];
    int n, i;

    clrscr();

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter percentage of each student:\n");
    for(i = 0; i < n; i++)
        scanf("%f", &percent[i]);

    selectionSort(percent, n);

    printf("\nPercentages in ascending order:\n");
    for(i = 0; i < n; i++)
        printf("%.2f ", percent[i]);

    printf("\n\nTop Five Percentages:\n");
    for(i = n-1; i >= n-5 && i >= 0; i--)
        printf("%.2f ", percent[i]);

    getch();
}
