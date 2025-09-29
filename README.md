# 00. Pitch

strcpy demo: why one takes longer than the other
find /usr/local: first find takes longer than the other
char * vs char[]: one works (char []) one doesn't
python string editing: show that string edits consume another string (strings are immutable in Python)

Conclusion: you have to understand what's happening behind the scenes
- as a software engineer you must understand how underlying software (and hardware) works
- as a F1 pilot, you have to understand how your car works, how the car engine works
- as a constructions engineer, you have to know about the materials, their durability, about joints and bolts

You need to understand the way software works at layers (and how hardware works, and how networking works).

# 01. Lecture Map

In this lecture we will walk through:
- software stack, roles of layers in software stack
- role of the operating system
- advantages and disadvantages of working at various layers in the software stack
- software types: applications and libraries
- interaction between software components

# 02. Software Stack

Software stands on top of hardware, but in layers.
Discuss / present layers (with demos):

- assembly
- C POSIX
- C ANSI
- C++
- Python
- Python server: python -m http.server 8080
- TODO: Flask framework: Flask Hello World

use strace throughout demos, show small differences between layers

stack is:
kernel -> libc -> language libraries / runtime -> frameworks -> applications

All layers offer interfaces: syscall API, C API, language API

Applications can be created at all levels: directly on top of kernel, on top of libs, on top of language libraries etc.
Trade control / efficient use of resources with efficient use of time / ease of integration and debugging. See more later.

Conclusion: There is a software stack, to make it easy to develop new software.
You rely on existing software (from the lower levels)
Higher up the stack: easier do develop, many choices of (programming languages / frameworks)
Lower down the stack: more control, improved performance

# 03. Kernel

OS: basic layer over hardware for management, arbitration and system services:
- execution / compute management: creation of processes, threads, memory allocation
- I/O management: opening of I/O devices, opening of files, multiplexing access

diagram with OS and syscall API

OS provides system call interface:
- memory management
- exection management
- I/O management
- filesystem work

fill diagram with components inside the kernel

OS internal details will be present in the next lecture

# 04. Versus

TODO: demo portability vs performance: Java, Python, C: Fibonacci, generare de fișier umplut cu zero-uri, copiere de fișier
TODO: resource efficiency vs performance: dimensiune mai mică sau mai mare buffer
security vs performance
TODO: security vs usability
TODO: modularity / maintainability vs comprehensibility: snippet from the Linux kernel

# 05. Applications and Libraries

software types: applications and libraries
applications have entry points, libraries have interface to be used by applications
libraries expose an API - they are to be used by applications
applications can also expose an API to other applications

But all provide services (software).

# 06. Interaction between Software Components

web browser and web server (+ libraries)

TODO: Docker-compose cu Wordpress and a database

Libraries provide services to other software components: libraries or applications.

Applications provide software services either to the user (end-user applications) or to other applications (server applications).

All software components, however, offer interfaces. The interface can be a UI (CLI, TUI, webUI, GUI) for applications that provide services to the user. The interface is of type API and/or protocol for software components that offer services to other software components (libraries to libraries, libraries to applications, server applications to other applications). The implementation of a protocol between applications is generally called IPC (inter-process communication; more correctly, inter-app communication).

# 07. Conclusion

In this lecture we will walk through:
- software stack, roles of layers in software stack
- role of the operating system
- advantages and disadvantages of working at various layers in the software stack
- software types: applications and libraries
- interaction between software components

Takeaway: A deep understanding of things gives you control, ability to make correct decisions (A vs B), confidence
