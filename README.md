**Arena Allocator (C / Linux)**

Project Milestone: Year 1, Quarter 1, Week 3

A high-performance linear "bump" allocator built from scratch. This project focuses on manual memory management, OS-level memory mapping, and hardware-level alignment requirements.

Technical Highlights
Virtual Memory Mapping: Uses mmap with MAP_ANONYMOUS and MAP_PRIVATE flags to request raw memory pages directly from the Linux kernel, bypassing malloc.

O(1) Allocation: Implementation of a "bump" strategy where allocation is a simple pointer addition, providing predictable, high-speed performance.

Manual Alignment Logic: Includes a custom bit-masking function (align_forward) to ensure all allocations are 8-byte aligned, preventing CPU bus errors and optimizing data access.

Memory Safety: Implements overflow protection to return NULL when the arena capacity is exceeded, ensuring the allocator remains stable under load.

How to Verify
Compile: Run make to build the Allocator_Arena_v1 binary.

Inspect Memory: The program prints the base memory address. While the program is sleeping, run cat /proc/<PID>/maps to verify the anonymous mapping exists at that exact address in the kernel's process map.

Check Alignment: Observe the output addresses; notice that even 1-byte allocations result in 8-byte offsets to maintain hardware alignment.
