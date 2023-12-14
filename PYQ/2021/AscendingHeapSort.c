#include<stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int insertHeap(int a[], int n) {
    int i = n;
    int temp = a[n];
    while (i > 1 && temp > a[i/2]) {
        a[i] = a[i/2];
        i /= 2;
    }
    a[i] = temp;
}

int deleteHeap(int a[], int n) {
    int val = a[1];
    a[1] = a[n];
    a[n] = val;
    int i = 1, j = 2*i;
    while (j < n-1) {
        if(a[j+1] > a[j]) j++;
        // }
        if (a[i] < a[j]) {
            swap(&a[i], &a[j]);
            i = j;
            j = 2*i;
        } else {
            break;
        }
    }
    return val;
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
    printf("Enter %d elements : ", size);
    // int a[] = {0, 3, 6, 8, 10, 11, 14};
    int a[size+1];
    a[0] = 0;
    for (int i = 1; i <= size; i++) {
        scanf("%d", &a[i]);
    }
    printf("Before sorting, elements are : ");
    display(a, 7);
    heapSort(a, size+1);

    // for (int i = 2; i <= 6; i++) {
    //     insertHeap(a, i);
    // }
    // for (int i = 6; i > 1; i--) {
    //     deleteHeap(a, i);
    // }
    printf("After sorting, elements are : ");
    display(a, 7);
    return 0;
}