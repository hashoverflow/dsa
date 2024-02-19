#include <stdio.h>
#include <stdlib.h>

int partition(int *a, int l, int r) {
    int p = l;
    for (int i = l; i < (r - 1); i++) {
        if (a[i] < a[r - 1]) {
            int t = a[p];
            a[p] = a[i];
            a[i] = t;
            p++;
        }
    }
    int t = a[p];
    a[p] = a[r - 1];
    a[r - 1] = t;
    return p;
}

void quick_sort(int *a, int l, int r) {
    if ((r - l) <= 1) return;
    int p = partition(a, l, r);
    quick_sort(a, l, p);
    quick_sort(a, p + 1, r);
}

int main() {
    int n;
    scanf("%d", &n);
    int *a = (int *)(malloc(sizeof(int) * n));
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    quick_sort(a, 0, n);
    for (int i = 0; i < n; i++) printf("%d%c", a[i], (i == (n - 1)) ? '\n' : ' ');
    return 0;
}