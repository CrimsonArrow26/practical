#include <stdio.h>
#include <conio.h>

void bubbleSort(float arr[], int n) {
    int i, j;
    float temp;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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

    bubbleSort(percent, n);

    printf("\nPercentages in ascending order:\n");
    for(i = 0; i < n; i++)
        printf("%.2f ", percent[i]);

    printf("\n\nTop Five Percentages:\n");
    for(i = n-1; i >= n-5 && i >= 0; i--)
        printf("%.2f ", percent[i]);

    getch();
}
