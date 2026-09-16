#include <stdio.h>
#include <string.h>
#include "vm.h"

int main()
{
  char op[4];
  unsigned rd, rs, rt;
  int off, immediate;

  instruction program[100];
  int next_position = 0;

  FILE *program_file;
  program_file = fopen("fibonacci.asm", "r");

  if (program_file == NULL)
  {
    printf("Could not open program file\n");
    return 1;
  }

  while (fscanf(program_file, "%3s", op) == 1)
  {

    if (!strcmp(op, "out"))
    {
      fscanf(program_file, " $%u", &rd);
      instruction this_instruction = {"out", rd, 0, 0, 0, 0};
      add_to_program(this_instruction, next_position, program);
    }

    else if (!strcmp(op, "add"))
    {
      fscanf(program_file, " $%u, $%u, $%u", &rd, &rs, &rt);
      instruction this_instruction = {"add", rd, rs, rt, 0, 0};
      add_to_program(this_instruction, next_position, program);
    }

    else if (!strcmp(op, "sub"))
    {
      fscanf(program_file, " $%u, $%u, $%u", &rd, &rs, &rt);
      instruction this_instruction = {"sub", rd, rs, rt, 0, 0};
      add_to_program(this_instruction, next_position, program);
    }

    else if (!strcmp(op, "mul"))
    {
      fscanf(program_file, " $%u, $%u, $%u", &rd, &rs, &rt);
      instruction this_instruction = {"mul", rd, rs, rt, 0, 0};
      add_to_program(this_instruction, next_position, program);
    }

    else if (!strcmp(op, "div"))
    {
      fscanf(program_file, " $%u, $%u, $%u", &rd, &rs, &rt);
      instruction this_instruction = {"div", rd, rs, rt, 0, 0};
      add_to_program(this_instruction, next_position, program);
    }

    // Logic Operations

    else if (!strcmp(op, "not"))
    {
      fscanf(program_file, " $%u, $%u", &rd, &rs);
      instruction this_instruction = {"not", rd, rs, 0, 0, 0};
      add_to_program(this_instruction, next_position, program);
    }

    else if (!strcmp(op, "or"))
    {
      fscanf(program_file, " $%u, $%u, $%u", &rd, &rs, &rt);
      instruction this_instruction = {"or", rd, rs, rt, 0, 0};
      add_to_program(this_instruction, next_position, program);
    }

    else if (!strcmp(op, "and"))
    {
      fscanf(program_file, " $%u, $%u, $%u", &rd, &rs, &rt);
      instruction this_instruction = {"and", rd, rs, rt, 0, 0};
      add_to_program(this_instruction, next_position, program);
    }

    // Memory Operations

    else if (!strcmp(op, "li"))
    {
      int result = fscanf(program_file, " $%u, %d", &rd, &immediate);
      instruction this_instruction = {"li", rd, 0, 0, immediate, 0};
      add_to_program(this_instruction, next_position, program);
    }

    else if (!strcmp(op, "lw"))
    {
      fscanf(program_file, " $%u, %d($%u)", &rd, &off, &rs);
      instruction this_instruction = {"lw", rd, rs, 0, 0, off};
      add_to_program(this_instruction, next_position, program);
    }

    else if (!strcmp(op, "sw"))
    {
      fscanf(program_file, " $%u, %d($%u)", &rd, &off, &rs);
      instruction this_instruction = {"sw", rd, rs, 0, 0, off};
      add_to_program(this_instruction, next_position, program);
    }

    // Branching Operations

    else if (!strcmp(op, "j")){
      fscanf(program_file, " %d", &immediate);
      instruction this_instruction = {"j", 0, 0, 0, immediate, 0};
      add_to_program(this_instruction, next_position, program);

    }

    else if (!strcmp(op, "beq")){
      fscanf(program_file, " $%u, $%u, %d", &rd, &rs, &off);
      instruction this_instruction = {"beq", rd, rs, 0, 0, off};
      add_to_program(this_instruction, next_position, program);
    }

    else
    {
      printf("Unknown instruction: %s\n", op);
    }

    next_position++;
  };

  fclose(program_file);
  execute_program(program, next_position);

  return 0;
}
