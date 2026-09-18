#ifndef BENCH_H
#define BENCH_H
// every single .h (header) file is essentially like building a "menu" of functions for the 
// larger c program compiled from the /src directory here :) 
//
// you always have to include in the .h file a header at the top like 
// "#ifndef BENCH_H
// #define BENCH_H"
//
// and you conclude it all with
//
// "#endif"
// :P
#include <stddef.h>
// timer & machine info
double benchmark_time_seconds(void);
void machine_info(void);
// memory access 
double sum_array_with_stride(const float *data, size_t length, size_t stride);
double sum_matrix_by_rows(const float *matrix, size_t rows, size_t columns);
double sum_matrix_by_columns(const float *matrix, size_t rows, size_t columns);
void copy_float_array(const float *source, float *destination, size_t length);
// matmuls
void matmul_naive(const float *a, const float *b, float *c, size_t n);
void transpose_square_matrix(const float *source, float *destination, size_t n);
void matmul_with_transposed_b(const float *a, const float *b_transposed, float *c, size_t n);
// threaded & serial sum 
double sum_array_serial(const float *data, size_t length);
double sum_array_threaded(const float *data, size_t length, size_t thread_count);
//ya, this is where the menu ends 
#endif
