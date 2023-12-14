#include<stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int l, int h) {
    int pivot = a[l];
    int i = l, j = h;
    while (i < j) {
        // do {i++;} while(a[i] <= pivot);
        // do {j--;} while(a[j] > pivot);
        while (a[i] <= pivot) {
            i++;
        }
        while (a[j] > pivot) {
            j--;
        }
        if (i < j) swap(&a[i], &a[j]);
    }
    swap(&a[l], &a[j]);
    return j;
}

void quickSort(int a[], int l, int h) {
    int j;
    if (l < h) {
        j = partition(a, l, h);
        // quickSort(a, l, j);
        quickSort(a, l, j-1);
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
    int size;
    printf("Enter size : ");
    scanf("%d", &size);
    int a[size];
    printf("Enter %d elements : ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }
    display(a, size);
    quickSort(a, 0, size-1);
    display(a, size);
    return 0;
}