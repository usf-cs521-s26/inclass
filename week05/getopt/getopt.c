#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int opt;
    while ((opt = getopt(argc, argv, "a:b")) != -1) {
        switch (opt) {
            case 'a':
                printf("found an a with value %s\n", optarg);
                break;
            case 'b':
                printf("found a b\n");
                break;
            default:
                printf("unrecognized arg: %c\n", opt);
        }
    }
}
