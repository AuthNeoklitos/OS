#include <stdio.h>

void add(int *a, int *b, int *c, int *sum) {
    *sum = *a + *b + *c;
}

int main() {
    int x = 1, y = 2, z = 2, sum;
    add(&x, &y, &z, &sum);
    printf("The sum is: %d\n", sum);
    return 0;
}
