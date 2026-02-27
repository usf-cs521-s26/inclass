#include <stdio.h>
#include <stdlib.h>

#define MAX_ARR 32

int sum_arr(int *arr, int start, int end) {
    // Base case
    if (start == end) {
        return 0;
    }

    // Recursive case
    // Decompose the data (start + 1), and call ourselves
    return arr[start] + sum_arr(arr, start + 1, end);
}

int main(int argc, char *argv[]) {
    int arr[MAX_ARR];
    for (int i = 1; i < argc; i++) {
        arr[i-1] = atoi(argv[i]);
    }

    int arr_len = argc - 1;
    int sum = 0;

    sum = sum_arr(arr, 0, arr_len);

    // This is an iterative solution, not a recursive solution
    // for (int j = 0; j < arr_len; j++) {
    //     sum += arr[j];
    // }

    printf("sum: %d\n", sum);
}
