#include<stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int l, int h) {
    int i = l, j = h;
    int pivot = a[l];
    while (i < j) {
        while (a[i] <= pivot) {i++;}
        while (a[j] > pivot) {j--;}
        if(i < j) swap(&a[i], &a[j]);
    }
    swap(&a[l], &a[j]);
    return j;
}

int quickSort(int a[], int l, int h) {
    int j;
    if (l <= h) {
        j = partition(a, l, h);
        quickSort(a, l, j);
        quickSort(a, j+1, h);
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");    
}

int main() {
    int a[] = {4, 6, 1, 9, 0, 6, 2}, n = 7;
    display(a, n);
    quickSort(a, 0, n-1);
    display(a, n);
    return 0;
}