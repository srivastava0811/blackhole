// prefilled code from me, rafan ! :D

// lets make 'machine_info()'

// this c program here lets us know what kind of machine/computer you are running these cpu execution benchmarks on! 
// and, this is very important to document when you run your experiments. very important. you guys will be running these
// benchmarks on fundamentally different hardware ofc! your:
//      cpu architecture, 
//      number of CPU cores
//      compiler and the version of it
//      operating environment
//      memory and cache hardware
// are all vastly different from one another! 

#if defined(__APPLE__)
#define _DARWIN_C_SOURCE
// ^ okkey, i am a mac user (as of sept 2026) so this header stuff for me exists. if you not a mac user, dont worry!!
//  macOS hides some of its extra system information when we request strict POSIX only like in this program 
//  and thiis is specifically for when we ask to reveal the logical-core option we need (lines 68-73) for us mac users!
//  Linux and Windows w/ WSL users: This skips this definition completely, so ya, dont worry!
#endif


#define _POSIX_C_SOURCE 200809L
#include "bench.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // --> we need this to declare operating system functions related to system configs, 
                    //     file ops, process ops, access to standard i/o, and sleep/timing related functions.
                    //                      in specific, we need 'sysconf()' and '_SC_NPROCESSORS_ONLN' here


void machine_info(void) {
    // Let us identify the operating system (is it mac, linux, or windows w/ wsl?):
    printf("Machine information:\n");
#if defined(__APPLE__) && defined(__MACH__)
    printf("Operating system: macOS\n");
#elif defined(__linux__)
    const char *wsl_distribution = getenv("WSL_DISTRO_NAME");
    if (wsl_distribution != NULL && wsl_distribution[0] != '\0') {printf("Operating system: Windows w/ WSL (%s)\n", wsl_distribution);}
    else {printf("Operating system: Linux\n");}
#else 
    printf("Operating system: Unknown\n");
#endif

    // Now, let us identify the CPU architecture:
#if defined(__aarch64__) || defined(__arm64__)
    printf("Architecture: ARM64\n");
#elif defined(__x86_64__)
    printf("Architecture: x86-64\n");
#else
    printf("Architecture: Unknown\n");
#endif

    // Then, we check and identify the compiler. 
    // Note that checking for Clang before GCC is order-sensitive because 
    // Clang also defines some GCC compatible macros :)
#if defined(__clang__) && defined(__apple_build_version__)
    printf("Compiler: Apple Clang %d.%d.%d\n", __clang_major__, __clang_minor__, __clang_patchlevel__);
#elif defined(__clang__)
    printf("Compiler: Clang %d.%d.%d\n", __clang_major__, __clang_minor__, __clang_patchlevel__);
#elif defined(__GNUC__)
    printf("Compiler: GCC %d.%d.%d\n", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
#else 
    printf("Compiler: Unknown\n");
#endif

    // Finally, we want to ask the OS how many logical CPU cores (the number of them) are
    // currently available in this program :D 
    long logical_cpu_cores = sysconf(_SC_NPROCESSORS_ONLN);
    if (logical_cpu_cores > 0) {printf("Logical CPU cores: %ld\n", logical_cpu_cores);}
    else {printf("Logical CPU cores: Unavailable\n");}
    printf("\n");
}
