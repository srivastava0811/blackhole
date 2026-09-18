// ================
// || main.c ||
// ================


// ||ABSTRACT||
// every C program begins executing through a function named 'main()'. in this lab, main is where we will organize
// our complete benchmark: 
//
// we will:
//          prepare the data, 
//          call the experiment functions written in the other source files,
//          measure their execution time, 
//          check their answers and print the results we want to compare.
//
// the experiment files are intentionally responsible for only their own computation. for example,
// 'copy_float_array()' copies the array, but it does not choose the array size, allocate the arrays or calculate
// bandwidth. these larger experiment decisions belong in this main program, so every function can be tested through one shared program.


#include "bench.h" // --> this provides the shared function menu for the source files in this lab
#include <stddef.h> // --> this provides 'size_t' for array lengths, matrix dimensions and byte counts
#include <stdio.h>  // --> this provides 'printf()' for displaying benchmark information and results
#include <stdlib.h> // --> this provides 'malloc()', 'free()' and tools for reporting allocation failure


int main(void){
    // ||STAGE 1: IDENTIFY THE MACHINE||
    // print the operating environment, CPU architecture, compiler and available logical CPU cores.
    // this gives important context because students will run these experiments on different computers.

    // ||YOUR CODE GOES BELOW HERE||:



    // ||STAGE 2: CHOOSE THE EXPERIMENT SETTINGS||
    // decide which array lengths, matrix dimensions, stride values, repetition counts and thread counts to test.
    // these settings should be large enough to measure meaningfully without requiring excessive memory or time.

    // ||YOUR CODE GOES BELOW HERE||:



    // ||STAGE 3: CREATE AND INITIALIZE THE DATA||
    // allocate the arrays and matrices needed by the experiments, verify every allocation and fill the inputs with
    // predictable values. predictable data gives us results that we can check after each experiment finishes.

    // ||YOUR CODE GOES BELOW HERE||:



    // ||STAGE 4: OBSERVE STRIDED ARRAY ACCESS||
    // run 'sum_array_with_stride()' with several stride values. time each run and confirm that every traversal returns
    // the same sum even though it requests the array elements in a different order.

    // ||YOUR CODE GOES BELOW HERE||:



    // ||STAGE 5: COMPARE ROW AND COLUMN ACCESS||
    // run 'sum_matrix_by_rows()' and 'sum_matrix_by_columns()' on the same row-major matrix. compare their times and
    // verify that both functions produce the same mathematical sum.

    // ||YOUR CODE GOES BELOW HERE||:



    // ||STAGE 6: MEASURE COPY BANDWIDTH||
    // time 'copy_float_array()', inspect the destination after the timed region and calculate effective bandwidth from:
    //              useful bytes moved = 2 * length * sizeof(float)
    //              effective GB/s = useful bytes moved / elapsed seconds / 1000000000.0

    // ||YOUR CODE GOES BELOW HERE||:



    // ||STAGE 7: COMPARE THE TWO MATRIX MULTIPLICATIONS||
    // create the transposed copy of B, then time 'matmul_naive()' and 'matmul_with_transposed_b()' separately. verify
    // that both produce the same output matrix and calculate their approximate performance using 2 * n * n * n FLOPs.
    // the transpose should be timed separately because rearranging B has its own cost.

    // ||YOUR CODE GOES BELOW HERE||:



    // ||STAGE 8: COMPARE SERIAL AND THREADED WORK||
    // time 'sum_array_serial()' and 'sum_array_threaded()' with the same input. verify their sums and calculate:
    //              speedup = serial elapsed seconds / threaded elapsed seconds
    // this experiment also lets us observe when thread coordination costs more time than it saves.

    // ||YOUR CODE GOES BELOW HERE||:



    // ||STAGE 9: RELEASE THE MEMORY||
    // free every allocation created by this program. each successful 'malloc()' should eventually have one matching
    // 'free()' after the final experiment that needs that memory has finished.

    // ||YOUR CODE GOES BELOW HERE||:



    // returning 0 tells the operating system that the program finished successfully.
    return 0;
}
