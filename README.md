Virtual Machine in C

A simple virtual machine and assembly-language interpreter written from scratch in C.

This project was built to develop a deeper understanding of how programs are represented, decoded and executed at a low level, including CPU registers, memory, instructions and the fetch-decode-execute cycle.

Project Overview

The virtual machine contains:

* 32 general-purpose 32-bit registers
* 64 KB of byte-addressable memory
* A program counter (PC)
* A custom instruction format
* An assembly-language parser
* A fetch-decode-execute execution cycle
* Support for arithmetic, logical, memory and control-flow instructions

Assembly programs are read from a .asm file, converted into instructions and stored in the VM’s program memory before being executed.

Architecture

The VM is split into two main components:

Assembler

The assembler reads an assembly program from a text file and parses each instruction.

For example:

li $1, 1
li $2, 0
add $3, $1, $2

Each instruction is converted into an instruction structure containing the opcode and relevant operands.

The instructions are then stored in an array representing the program loaded into the virtual machine.

Virtual Machine

The VM maintains the state of the simulated CPU:

* Registers — 32 general-purpose 32-bit registers
* Memory — 64 KB of byte-addressable memory
* Program Counter — tracks the current instruction
* Program — stores the decoded instructions

Instructions are executed using a fetch-decode-execute cycle.

Instruction Set

The current instruction set includes:

Arithmetic Operations:
add	Add two registers
sub	Subtract two registers
mul	Multiply two registers
div	Divide two registers

Logic Operations:
and	Logical AND
or	Logical OR
not	Logical NOT

Memory and Immediate Operations:
li	Load an immediate value into a register
lw	Load a value from memory
sw	Store a value in memory

Branching Operations:
beq	Branch if two registers are equal
j	Jump to a program location

I/O Operations:
out	Output the value of a register

Example Program

One of the first non-trivial programs written for the VM is a Fibonacci sequence implementation.

The program uses registers to store the current Fibonacci values, temporary values, constants and the iteration counter.

li $1, 1
li $2, 0
li $3, 0
li $4, 0
li $5, 1
li $6, 5
li $7, 0
add $3, $1, $2
add $2, $1, $4
add $1, $3, $4
add $7, $7, $5
beq $6, $7, 1
j 6

This demonstrates that the VM can execute arithmetic operations, maintain state across instructions and use conditional branching and jumps to implement a loop.

Building and Running

Compile the project with clang on Mac:

clang assembler.c vm.c -o emulator

Then run an assembly program:

./emulator

The assembler reads the configured .asm file and passes the resulting program to the virtual machine for execution.

What I Learned

This project has been primarily about understanding the concepts behind a CPU and an instruction execution pipeline rather than simply implementing a working program.

In particular, it has helped me understand:

* How registers can be used as CPU state
* How instructions can be represented as C structures
* How an assembly program can be parsed into machine-readable instructions
* How the program counter controls execution
* How branching and jumps alter program flow
* How the fetch-decode-execute cycle works
* How C structures, arrays, pointers and functions can be used to model hardware concepts

Future Improvements

Planned improvements include:

* Implement labels in the assembler to replace hard-coded jump addresses
* Add a proper HALT instruction
* Improve parsing and error handling
* Add more memory operations
* Add a debug/trace mode to inspect registers and program execution
* Expand the instruction set
* Improve the assembler’s handling of invalid programs
* Implement pipelining to improve efficiency

Technologies

* C
* Clang
* Assembly
* Git
