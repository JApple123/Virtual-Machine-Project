#ifndef VM_H
#define VM_H

typedef struct {
    char opcode[4];
    unsigned rd;
    unsigned rs;
    unsigned rt;
    int immediate;
    int offset;
} instruction;

void add_to_program(instruction this_instruction, int next_position, instruction program[]);

void execute_program(instruction program[], int next_position);

#endif