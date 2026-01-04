#include <stdio.h>

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main(void) {
    const int num = 5;
    const int result = factorial(num);
    printf("%d! = %d\n", num, result);
    return 0;
}
