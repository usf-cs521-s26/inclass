#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

void print_list(struct node *list) {
    while (list != NULL) {
        printf("Node %p val: %d\n", list, list->val);
        list = list->next;
    }
}

void free_list(struct node *list) {
    while (list) {
        struct node *tmp = list->next;
        list = list->next;
        free(tmp);
    }
}

int main(int argc, char *argv[]) {
    struct node *n1 = malloc(sizeof(struct node));
    n1->val = 1;
    n1->next = NULL;

    struct node *n2 = malloc(sizeof(struct node));
    n2->val = 2;
    n2->next = NULL;
    n1->next = n2;

    print_list(n1);
    free_list(n1);
}
