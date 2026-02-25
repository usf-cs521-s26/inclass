#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MAKE 32

struct car {
    int year;
    char make[MAX_MAKE];
};

struct car *new_car(int year, char *make) {
    struct car *pc = malloc(sizeof(struct car));
    pc->year = year;
    strncpy(pc->make, make, MAX_MAKE - 1);
    return pc;
}

void print_car(struct car *pc) {
    printf("year: %d, make: %s\n", (*pc).year, pc->make);
}

int main(int argc, char*argv[]) {

    char *model = "911";
    model[0] = 'x';

    struct car *porsche = new_car(2026, "Porsche");
    print_car(porsche);
    //free(porsche);

    while (1) {
        struct car *pc = new_car(2025, "HOnda");
//        print_car(pc);
    }
}
