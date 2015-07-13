#include <stdio.h>

int MaxInt() {
    return -1u>>1;
}

void Merge(int *A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int *L = new int[n1 + 1];
    int *R = new int[n2 + 1];

    for(int i = 0; i < n1; i++)
        L[i] = A[p+i];
    L[n1] = MaxInt();

    for(int j = 0; j < n2; j++)
        R[j] = A[q+j+1];
    R[n2] = MaxInt();

    int i = 0;
    int j = 0;
    for(int k = p; k <= r; k++)
        if(L[i] <= R[j]) A[k] = L[i++];
        else A[k] = R[j++];
    delete L;
    delete R;
}

void MergeSort(int *A, int p, int r) {
    if(p < r) {
        int q = (r + p)/2;
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        Merge(A, p, q, r);
    }
}

int main()
{
    int arr[] = {3, 0, -2, 1, 4, -1, 6, 5, 2};
    printf("Before applying MergeSort...\n");
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
        printf("%d\t", arr[i]);
    printf("\nAfter applying MergeSort...\n");
    MergeSort(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1);
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
        printf("%d\t", arr[i]);

    return 0;
}
