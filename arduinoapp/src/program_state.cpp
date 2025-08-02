
#include "program_state.hpp"

ProgramState *p_program_state = (ProgramState *)malloc(sizeof(ProgramState));

void init_program_state() { p_program_state->sleep = true; }