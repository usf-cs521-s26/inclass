
// stdio.h is a header file which contains the declaration for printf()
#include <stdio.h>

int count_e(char *s) {
    int num_e = 0;
    // In C, single quotes mark characters, double quotes mark strings
    while (*s != '\0') {
        if (*s == 'e') {
            // Increment the count
            num_e++;
        }
        // Walk s forward to the next char
        s++;
    }
    return num_e;
}

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        // %d is a "format specifier" which means print in decimal
        // %s means print as a string
        char *s = argv[i];
        int num_e = count_e(s);
        printf("%s contains %d e\n", s, num_e);
    }
}
