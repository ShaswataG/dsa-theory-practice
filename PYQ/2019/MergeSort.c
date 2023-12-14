#include<stdio.h>

void merge(int a[], int l, int mid, int h) {
    int i = l, j = mid+1, k = l;
    int b[h+1];
    while (i <= mid && j <= h) {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= mid)
        b[k++] = a[i++];
    while (j <= h)
        b[k++] = a[j++];
    for (int i = l; i <= h; i++) {
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


int main() {
    int size;
    printf("Enter size : ");
    scanf("%d", &size);
    int a[size];
    printf("Enter %d elements : ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }
    printf("Before sorting, elements are : ");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    mergeSort(a, 0, size-1);
    printf("After sorting, elements are : ");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}