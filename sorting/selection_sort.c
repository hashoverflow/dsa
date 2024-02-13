#include <stdio.h>
#include <stdlib.h>

void selection_sort(int *a, int n) {
    int min, k;
    for (int i = 0; i < (n - 1); i++) {
        min = a[i];
        k = i;
        for (int j = (i + 1); j < n; j++) {
            if (a[j] < min) {
                min = a[j];
                k = j;
            }
        }
        a[k] = a[i];
        a[i] = min;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int *a = (int *)(malloc(sizeof(int) * n));
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    selection_sort(a, n);
    for (int i = 0; i < n; i++) printf("%d%c", a[i], (i == n - 1) ? '\n' : ' ');
    return 0;
}