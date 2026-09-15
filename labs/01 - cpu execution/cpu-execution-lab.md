# CPU Execution Lab 
### September 14th - 18th, 2026

This lab is a demonstration of written program code's relationship with the CPU of our computers. Written code turns into smaller blocks of work that live in the CPU, which include [**machine instructions**](https://pages.cs.wisc.edu/~markhill/cs354/Fall2008/notes/basics.html), [**memory reads/writes**](https://pages.cs.wisc.edu/~markhill/cs354/Fall2008/notes/basics.html), [**cache behavior**](https://www.cs.cornell.edu/courses/cs3410/2024fa/notes/caches.html), and [**performance differences**](https://www.cs.cornell.edu/courses/cs3410/2025sp/notes/pipelining.html). We write and showcase all of this in the form of constructing basic matrix multiplication (matmul), since this computation is fundamental in Machine Learning workloads and hardware accelerator designs. 

Matmuls also work quite well for showing how data moves differently based on simple changes within the operation itself. Tenstorrent's Blackhole, then, can be thought of as a later extension of these same ideas, but at scale, with topics that this lab should serve as a foundation for: 
- [**local memory near compute**](https://docs.tenstorrent.com/tt-metal/latest/tt-metalium/tt_metal/labs/matmul/lab1/lab1.html), 
- [**many parallel workers**](https://docs.tenstorrent.com/aibs/blackhole/installation.html), 
- [**explicit data movement**](https://docs.tenstorrent.com/tt-metal/latest/tt-metalium/tt_metal/apis/kernel_apis/data_movement/data_movement.html), 

and 

- [**specialized hardware for ML-shaped computation**](https://docs.tenstorrent.com/tt-metal/latest/tt-metalium/tt_metal/advanced_topics/compute_engines_and_dataflow_within_tensix.html). 

