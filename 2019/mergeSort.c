#include<stdio.h>

void merge(int a[], int l, int mid, int h) {
    int i = l, j = mid+1;
    int b[h];
    int k = l;
    while (i <= mid && j < h) {
        if (a[i] < a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }
    while (i <= mid) {
        b[k++] = a[i++];
    }
    while (j < h) {
        b[k++] = a[j++];
    }
    for (int i = l; i < h; i++) {
        a[i] = b[i];
    }
}

void mergeSort(int a[], int l, int h) {
    int mid;
    if (l < h) {
        mid = (l+h)/2;
        mergeSort(a, l, mid);
        mergeSort(a, mid+1, h);
        merge(a, l, mid, h);
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[] = {3, 1, 6, 4, 1, 9, 2}, n = 7;
    display(a, n);
    mergeSort(a, 0, n-1);
    display(a, n);
    return 0;
}