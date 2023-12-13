#include<stdio.h>

void swap(int* ptrA, int* ptrB) {
    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;
}

void selectionSort(int a[], int n) {
    int min;
    for (int i = 0; i < n; i++) {
        min = i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[min]) min = j;
        }
        swap(&a[i], &a[min]);
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[] = {6, 5, 2, 9, 4, 2, 0}, n = 7;
    display(a, n);
    selectionSort(a, n);
    display(a, n);
    return 0;
}