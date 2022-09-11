#include "./two_dem_array.h"

int main() {
    int M = 0, N = 0;
    
    if (!scan_arr_size(&M, &N)) {
        int** arr = allocate_arr_memory(M, N);
        if (arr != NULL) {
            init_arr(arr, M, N);
            print_arr(arr, M, N);
            free_arr_memory(arr, M, N);
        } else { err_printer(1); }
    }

    return 0;
}

int scan_arr_size(int* m, int* n) {
    char ch = '\n';
    int one = 0, two = 0, exit = 0;

    if (!exit && (scanf("%d%d%c", &one, &two, &ch) != 3 || ch != '\n')) {
        buffer_cleaner();
        exit = 1;
        err_printer(2);
    }

    if (!exit && (one <= 0 || two <= 0)) {
        exit = 1;
        err_printer(3);
    }

    if (!exit) {
        *m = one;
        *n = two;
    }

    return exit;
}

int** allocate_arr_memory(int m, int n) {
    int** array = malloc(m * sizeof(int*));

    for (int i = 0; i < m; i++) {
        array[i] = malloc(n * sizeof(int));
    }

    return array;
}

void free_arr_memory(int** array, int m, int n) {
    for (int i = 0; i < 0; i++) {
        free(array[i]);
    }

    free(array);
}

void init_arr(int** array, int m, int n) {
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            array[i][j] = ++count;
        }
    }
}

void print_arr(int** array, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j != n - 1) {
                printf("%02d ", array[i][j]);
            } else { printf("%02d", array[i][j]); }
        }
        printf("\n");
    }
}

void err_printer(int err_num) {
    switch (err_num) {
    case 1:
        printf("ERROR: Can't create array\n");
        break;

    case 2:
        printf("ERROR: Somesthing printed after array sizes\n");
        break;

    case 3:
        printf("ERROR: Sizes should be larger than zero\n");
        break;

    default:
        break;
    }
}

void buffer_cleaner() {
    for (int c = getchar(); c != '\n' && c != EOF; c = getchar()) {}
}
