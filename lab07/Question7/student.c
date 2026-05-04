#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);

        if (i < size - 1) {
            printf(" ");
        }
    }
    printf("]\n");
}


int isSorted(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i - 1] > arr[i]) {
            return 0;
        }
    }
    return 1;
}


void insertionSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while ( j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void merge(int arr[], int left, int mid, int right) {
    int L[100], R[100];
    int n1 = mid - left + 1;
    int n2 = right - mid;

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void hybridMergeSort(int arr[], int left, int right, int k) {
    if (right - left + 1 <= k) {
        insertionSort(arr, left, right);
        return;
    }

    int mid = (left + right) / 2;
    hybridMergeSort(arr, left, mid, k);
    hybridMergeSort(arr, mid + 1, right, k);
    merge(arr, left, mid, right);
}

int main() {
    int arr[] = {39, 9, 81, 45, 90, 27, 72, 18};
    int size = sizeof(arr) / sizeof(arr[0]);

    int k = 3;

    printf("Original array:\n");
    printArray(arr, size);

    hybridMergeSort(arr, 0, size - 1, k);

    printf("Sorted array:\n");
    printArray(arr, size);

    if (isSorted(arr, size)) {
        printf("Result: PASS\n");
    } else {
        printf("Result: FAIL\n");
    }

    return 0;
}