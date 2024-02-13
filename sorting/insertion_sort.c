#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *a, int n) {
    int j, temp;
    for (int i = 1; i < n; i++) {
        j = i;
        temp = a[i];
        while (j && a[j - 1] > temp) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = temp;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int *a = (int *)(malloc(sizeof(int) * n));
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    insertion_sort(a, n);
    for (int i = 0; i < n; i++) printf("%d%c", a[i], (i == n - 1) ? '\n' : ' ');
    return 0;
}