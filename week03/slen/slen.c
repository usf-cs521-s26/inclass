#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        // Crash avoidance: make sure argv[1] will be valid
        printf("invalid args\n");
        return -1; // failure
    }

    char *s = argv[1];
    int len = 0;
    while (*s != '\0') {
        len++;      // increment len
        s++;        // walk pointer forward to next char
    }

    printf("len: %d\n", len);
    return 0; // success
}
