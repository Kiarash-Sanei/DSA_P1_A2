#include <stdio.h>

int findCandidate(int arr[], int start, int end) {
    int maj_index = start;
    int count = 1;
    for (int i = start + 1; i <= end; i++) {
        if (arr[maj_index] == arr[i])
            count++;
        else
            count--;
        if (count == 0) {
            maj_index = i;
            count = 1;
        }
    }
    return arr[maj_index];
}

int isMajority(int arr[], int start, int end, int cand) {
    int count = 0;
    for (int i = start; i <= end; i++)
        if (arr[i] == cand)
            count++;
    if (count > (end - start + 1) / 2)
        return cand;
    return 0;
}

int findMajority(int arr[], int start, int end) {
    int candidate = findCandidate(arr, start - 1, end - 1);
    return isMajority(arr, start - 1, end - 1, candidate);
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", findMajority(arr, l, r));
    }
    
    return 0;
}
