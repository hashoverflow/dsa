#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *a, int n) {
    int temp;
    for (int i = (n - 1); i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int *a = (int *)(malloc(sizeof(int) * n));
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    bubble_sort(a, n);
    for (int i = 0; i < n; i++) printf("%d%c", a[i], (i == n - 1) ? '\n' : ' ');
    return 0;
}