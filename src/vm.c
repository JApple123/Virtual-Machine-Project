#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "vm.h"

uint8_t memory[64*1024];

struct {
  uint32_t registers[32];
  uint32_t pc;
} cpu;

void out_instruction(unsigned r1){
  printf("%u\n", cpu.registers[r1]);
}

// Arithmetic Opertations

void add_instruction(unsigned r1, unsigned r2, unsigned r3)  
{
  cpu.registers[r1] = cpu.registers[r2] + cpu.registers[r3];
}

void sub_instruction(unsigned r1, unsigned r2, unsigned r3)
{
  cpu.registers[r1] = cpu.registers[r2] - cpu.registers[r3];
}

void mul_instruction(unsigned r1, unsigned r2, unsigned r3)
{
  cpu.registers[r1] = cpu.registers[r2] * cpu.registers[r3];
}

void div_instruction(unsigned r1, unsigned r2, unsigned r3)
{
  cpu.registers[r1] = cpu.registers[r2] / cpu.registers[r3];
}

// Logic Operations

void not_instruction(unsigned r1, unsigned r2)
{
  cpu.registers[r1] = 1 - cpu.registers[r2];
}

void or_instruction(unsigned r1, unsigned r2, unsigned r3)
{
  cpu.registers[r1] = cpu.registers[r2] + cpu.registers[r3] - ((cpu.registers[r2]) * (cpu.registers[r3]));
}

void and_instruction(unsigned r1, unsigned r2, unsigned r3)
{
  cpu.registers[r1] = cpu.registers[r2] * cpu.registers[r3];
}



// Memory Operations

void load_word(unsigned r1, unsigned r2, unsigned offset)
{
  unsigned address = cpu.registers[r2];
  cpu.registers[r1] = memory[address + offset];
}

void store_word(unsigned r1, unsigned r2, unsigned offset)
{
  unsigned address = cpu.registers[r2];
  memory[address + offset] = cpu.registers[r1];
}

void load_immediate(unsigned r1, unsigned immediate)
{
  cpu.registers[r1] = immediate;
}


// Branching Opperations

void branch_if_equal(unsigned r1, unsigned r2, unsigned offset)
{
  if (cpu.registers[r1] == cpu.registers[r2]){
    cpu.pc += offset;
  };

}

void jump(unsigned immediate)
{
  cpu.pc = immediate;
}


void add_to_program(instruction this_instruction, int next_position, instruction program[]){
  program[next_position] = (this_instruction);
}

void execute_program(instruction program[], int next_position){

  while (cpu.pc < next_position){
    instruction current_instruction = program[cpu.pc];

    if (!strcmp(current_instruction.opcode, "out")){
      out_instruction(current_instruction.rd);
    }

    else if (!strcmp(current_instruction.opcode, "li")){
      load_immediate(current_instruction.rd, current_instruction.immediate);
    }

    else if (!strcmp(current_instruction.opcode, "lw")){
      load_word(current_instruction.rd, current_instruction.rs, current_instruction.offset);
    }

    else if (!strcmp(current_instruction.opcode, "sw")){
      store_word(current_instruction.rd, current_instruction.rs, current_instruction.offset);
    }

    else if (!strcmp(current_instruction.opcode, "sub")){
      sub_instruction(current_instruction.rd, current_instruction.rs, current_instruction.rt);
      printf("Subtraction result = %u\n", cpu.registers[3]);
    }

    else if (!strcmp(current_instruction.opcode, "add")){
      add_instruction(current_instruction.rd, current_instruction.rs, current_instruction.rt);
      // printf("Addition result = %u\n", cpu.registers[3]);

    }

    else if (!strcmp(current_instruction.opcode, "mul")){
      mul_instruction(current_instruction.rd, current_instruction.rs, current_instruction.rt);
      printf("Multiplication result = %u\n", cpu.registers[3]);
    }

    else if (!strcmp(current_instruction.opcode, "div")){
      div_instruction(current_instruction.rd, current_instruction.rt, current_instruction.rs);
      printf("Division result = %u\n", cpu.registers[3]);
    }

    else if (!strcmp(current_instruction.opcode, "beq")){
      branch_if_equal(current_instruction.rd, current_instruction.rs, current_instruction.offset);
      
    }

    else if (!strcmp(current_instruction.opcode, "j")){
      jump(current_instruction.immediate);
    }

    cpu.pc++;

  }

  


}