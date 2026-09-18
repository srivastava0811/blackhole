// prefilled code from me, rafan !

// lets make 'benchmark_time_seconds(void)' !

#define _POSIX_C_SOURCE 200809L
// ^ this _POSIX_C_SOURCE is called a FEATURE-TEST MACRO!
// it asks the system headers to show us the POSIX.1-2008 interfaces that the
// operating system already supports. this works for our lab on macOS, Linux, and Windows w/ WSL!

#include "bench.h" // --> see include/bench.h comments :)
#include <stdio.h> // --> 'perror()' lets the operating system tell us why reading the clock failed
#include <stdlib.h>// --> if we cannot get a valid timestamp, 'exit()' and 'EXIT_FAILURE' help us stop the program instead of continuing with a meaningless benchmark!
#include <time.h> // --> 'struct timespec', 'clock_gettime()', and 'CLOCK_MONOTONIC' are declared in this header when the requested POSIX interface is available.

double benchmark_time_seconds(void) { // 'void' means this function takes no parameters!
        // 'struct timespec' stores time in 2 fields:
        // timestamp.tv_sec  = whole seconds
        // timestamp.tv_nsec = the remaining nanoseconds
    struct timespec timestamp;
        // 'clock_gettime()' takes 2 arguments and returns 0 on success or a
        // nonzero value on failure:
        //      1. CLOCK_MONOTONIC selects the clock we use to measure elapsed time.
        //      2. &timestamp gives the function the memory address where it can load
        //         the clock result.
    if (clock_gettime(CLOCK_MONOTONIC, &timestamp) != 0) {
        perror("clock_gettime");
        exit(EXIT_FAILURE);
    }
        // TLDR: if reading the clock fails (yeilds a nonzero value) and then it tells us what happened... then end the program!
    return (double)timestamp.tv_sec + (double)timestamp.tv_nsec / 1000000000.0; // --> convert the whole seconds + leftover nanoseconds into one seconds value
}
