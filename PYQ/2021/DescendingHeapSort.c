#include<stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertHeap(int a[], int n) {
//  creating a min heap
    int temp = a[n];
    int i = n;
    while (i > 1 && temp < a[i/2]) {
        a[i] = a[i/2];
        i /= 2;
    }
    a[i] = temp;
}

void deleteHeap(int a[], int n) {
    int val = a[1];
    a[1] = a[n];
    a[n] = val;
    int i = 1, j = 2*i;
    while (j < n-1) {
        if (a[j] > a[j+1]) j++;
        if (a[i] > a[j]) {
            swap(&a[i], &a[j]);
            i = j;
            j = 2*i;
        } else {
            break;
        }
    }
}

void heapSort(int a[], int n) {
    for (int i = 2; i < n; i++) {
        insertHeap(a, i);
    }
    for (int i = n-1; i > 1; i--) {
        deleteHeap(a, i);
    }
}

void display(int a[], int n) {
    for (int i = 1; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter size : ");
    scanf("%d", &size);
    int a[size+1];
    a[0] = 0;
    printf("Enter %d elements : ", size);
    for (int i = 1; i <= size; i++) {
        scanf("%d", &a[i]);
    }
    display(a, size+1);
    heapSort(a, size+1);
    display(a, size+1);
    return 0;
}