# Setup: CPU Execution Lab

## Required Tools

You need three things:

1. **Git**
   Used to clone the shared curriculum repository and submit changes.

2. **A C compiler**
   Used to build the benchmark programs directly from the terminal.

3. **A terminal**
   Used to run setup, build, and benchmark commands.

You do not need CMake, Tenstorrent hardware, TT-Metal, Python packages, Docker,
or a GPU for this first lab.

## Check Your Setup

Open a terminal and run:

```sh
git --version
cc --version
```

If both commands print version information, you are ready for the core lab.

If `cc --version` does not work on your system, try:

```sh
gcc --version
clang --version
```

At least one C compiler should be available.

## macOS

Install the Xcode Command Line Tools:

```sh
xcode-select --install
```

Then verify:

```sh
git --version
cc --version
```

## Linux

On Ubuntu or Debian:

```sh
sudo apt update
sudo apt install git build-essential
```

Then verify:

```sh
git --version
cc --version
```

Other Linux distributions may use a different package manager, but the needed
tools are the same: Git and a C compiler.

## Windows

The recommended path for this lab is **Windows Subsystem for Linux (WSL)**. This
gives Windows students a Linux-like development environment and keeps the lab
commands close to the macOS/Linux workflow.

In PowerShell or Windows Terminal, check whether WSL is installed:

```powershell
wsl --status
```

or:

```powershell
wsl --list --verbose
```

If WSL is not installed, run:

```powershell
wsl --install
```

After installing WSL, open Ubuntu from the Start menu and install the lab tools:

```sh
sudo apt update
sudo apt install git build-essential
```

Then verify inside Ubuntu/WSL:

```sh
git --version
cc --version
```

Native Windows builds with Visual Studio or MinGW may also work, but WSL is the
recommended path for this lab.

## Clone The Repository

Use the repository URL provided by the instructor:

```sh
git clone <repo-url>
cd blackhole
```

Then enter this lab folder:

```sh
cd "labs/01 - cpu execution"
```

## Build The Lab

From the lab folder:

```sh
cc -std=c11 -O2 -Wall -Wextra -pedantic -Iinclude src/*.c -o cpu_lab
```

This command asks the C compiler to build all source files in `src/`, use the
shared declarations in `include/`, and create one executable named `cpu_lab`.

On native Windows, the executable may be named with `.exe`:

```sh
cc -std=c11 -O2 -Wall -Wextra -pedantic -Iinclude src/*.c -o cpu_lab.exe
```

## Run The Benchmark

After building, run the benchmark:

```sh
./cpu_lab
```

On native Windows:

```sh
./cpu_lab.exe
```

The program should print several experiments about CPU execution and data
movement, such as:

- strided array access
- row-major vs column-major traversal
- memory copy bandwidth
- naive matrix multiplication
- transposed matrix multiplication
- optional threaded sum

## Optional: Generate Assembly

Different computers may produce different assembly. That is expected. The goal is
not to memorize exact instructions. The goal is to recognize patterns:

- registers
- loads
- stores
- arithmetic
- branches
- loops

To generate assembly for one source file with GCC or Clang:

```sh
cc -std=c11 -O2 -Iinclude -S src/stride_access.c -o stride_access.s
```

You can replace `src/stride_access.c` with another file, such as
`src/matmul_naive.c`.

Your instructor may also use Compiler Explorer or provide selected assembly
snippets during the lab.

## Optional: Threading Experiment

The threaded benchmark may be optional because C threading support differs across
platforms. On macOS, Linux, and WSL, POSIX threads are usually available.

If the lab supports threaded benchmarks, build with:

```sh
cc -std=c11 -O2 -Wall -Wextra -pedantic -DENABLE_THREADS -Iinclude src/*.c -o cpu_lab -pthread
```

If this does not work on your machine, that is okay. The core lab does not depend
on the threaded experiment.

## Troubleshooting

If no C compiler is found, install the platform tools for your operating system:

- macOS: Xcode Command Line Tools
- Linux/WSL: `build-essential`
- Windows native: Visual Studio Build Tools or MinGW

If `src/*.c` does not work in your native Windows terminal, use WSL or list the
source files explicitly in the compiler command.

If the benchmark runs but your timings differ from another student's timings,
that is normal. CPU model, operating system, compiler, background programs, and
power settings can all affect performance.

For this lab, focus on the pattern:

> When the code changes how data moves through memory, performance can change
> even when the mathematical result stays the same.
