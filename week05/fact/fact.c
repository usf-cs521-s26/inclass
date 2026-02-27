#include <stdio.h>
#include <stdlib.h>

int fact(int n) {
    // Base case
    if (n <= 1) {
        return 1;
    }

    // Recursive case
    // Decompose data (n-1) and call ourselves
    return n * fact(n-1);
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("invalid args\n");
        return -1;
    }

    int n = atoi(argv[1]);
    int f = fact(n);
    printf("%d\n", f);
}
