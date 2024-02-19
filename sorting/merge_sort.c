#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void merge(int *a, int l, int r, int c) {
    int *half_l = (int *)(malloc(sizeof(int) * (c - l + 1)));
    for (int i = 0; (l + i) < c; i++) half_l[i] = a[l + i];
    half_l[c - l] = INT_MAX;
    int *half_r = (int *)(malloc(sizeof(int) * (r - c + 1)));
    for (int i = 0; (c + i) < r; i++) half_r[i] = a[c + i];
    half_r[r - c] = INT_MAX;
    int p_l = 0, p_r = 0;
    for (int i = l; i < r; i++) {
        if (half_l[p_l] < half_r[p_r]) {
            a[i] = half_l[p_l];
            p_l++;
        } else {
            a[i] = half_r[p_r];
            p_r++;
        }
    }
}

void merge_sort(int *a, int l, int r) {
    if ((r - l) == 1) return;
    int c = (l + r) / 2;
    merge_sort(a, l, c);
    merge_sort(a, c, r);
    merge(a, l, r, c);
}

int main() {
    int n;
    scanf("%d", &n);
    int *a = (int *)(malloc(sizeof(int) * n));
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    merge_sort(a, 0, n);
    for (int i = 0; i < n; i++) printf("%d%c", a[i], (i == (n - 1)) ? '\n' : ' ');
    return 0;
}