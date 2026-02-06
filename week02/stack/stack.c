#include <string.h>
#include <stdio.h>

int print_string(char *fmt, char *val) {
    printf(fmt, val);
}

int main(int argc, char *argv[]) {
    char buf[4];
    char *p = buf;
    strncpy(buf, "foo", 4);
    print_string("buf: %s\n", buf);
    printf("p: %p\n", p);
}
