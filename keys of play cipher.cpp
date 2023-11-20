#include <stdio.h>

long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int n = 24;
    long long numKeys = factorial(n) / 2;
    printf("Number of effectively unique keys (considering 'J'/'I' equivalence): %lld\n", numKeys);

    return 0;
}

