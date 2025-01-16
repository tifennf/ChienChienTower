#ifndef __PROGRAMSTATE__
#define __PROGRAMSTATE__

#include "ble.hpp"

// program state
struct ProgramState {
    BLEState* p_ble_state;
    int sleep;
};

extern ProgramState*
    p_program_state;  // exporting program state to make it available everywhere

void init_program_state();

#endif