#include<stdio.h>

int LSearch(int a[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (a[i] == key) 
            return i;
    }
    return -1;
}

int BSearch(int a[], int n, int key) {
/*
TC = O(logn)
SC = O(n)
AS = O(1)
*/
    int l = 0, h = n-1;
    int mid;
    while (l <= h) {
        mid = (l+h)/2;
        if (key == a[mid]) {
            return mid;
        }
        else if (key < a[mid]) {
            h = mid-1;
        }
        else {
            l = mid+1;
        }
    }
    return -1;
}

int main() {
    int a[] = {1, 2, 3, 3, 5, 7, 11}, n = 6;
    int key = 99;
    printf("%d", BSearch(a, n, key));
    return 0;
}