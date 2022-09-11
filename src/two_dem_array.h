#ifndef TWO_DEM_ARRAY_H_
#define TWO_DEM_ARRAY_H_
#include <stdio.h>
#include <stdlib.h>

int scan_arr_size(int* m, int* n);
int** allocate_arr_memory(int m, int n);
void free_arr_memory(int** array, int m, int n);
void init_arr(int** array, int m, int n);
void print_arr(int** array, int m, int n);
void err_printer(int err_num);
void buffer_cleaner();

#endif  // TWO_DEM_ARRAY_H_