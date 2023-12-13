#include<stdio.h>

void swap(int* ptrA, int* ptrB) {
    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;
}

void bubbleSort(int a[], int n) {
    int flag = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (a[j] > a[j+1]) {
                swap(&a[j], &a[j+1]);
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[] = {53, 6, 5, 11, 8, 0}, n = 6;
    display(a, n);
    bubbleSort(a, n);
    display(a, n);
    return 0;
}