#include <stdio.h>



int main() {
    int zero = 0;
    if (zero == -0)
        printf("equal negative zero\n");
    if (zero == +0)
        printf("equal postive zero\n");
    if (zero == 0.0)
        printf("equal float 0.0\n");
    if (zero == +0.0)
        printf("equal postive float 0.0\n");
    if (zero == -0.0)
        printf("equal negative float 0.0\n");

    // +0.0 == 0.0
    if (+0.0 > 0.0)
        printf("+0.0 > 0.0\n");

    // -0.0 == 0.0
    double r = 0.0;
    r = r*-1;
    if (r >= 0.0)
        printf("-0.0 > 0.0\n");

    double x = 1e-200;
    double y = 1e-200 * x;
    printf("Reciprocal of +0: %g\n", 1/y);
    y = -1e-200*x;
    printf("Reciprocal of -0: %g\n", 1/y);

    return 0;
}
