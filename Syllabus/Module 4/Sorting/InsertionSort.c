#include<stdio.h>

void insertionSwap(int a[], int n) {
    int j;
    int temp;
    for (int i = 1; i < n; i++) {
        j = i-1;
        temp = a[i];
        while (j >= 0 && temp < a[j]) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[] = {6, 4, 1, 3, 9, 0}, n = 6;
    display(a, n);
    insertionSwap(a, n);
    display(a, n);
    return 0;
}