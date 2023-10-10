#ifndef MAIN_H_
#define MAIN_H_

#include <stdint.h>
#include "SysTick.h"
#include "msp432p401r.h"

// Define pointers to states for better readability
#define goN &FSM[0]
#define waitN &FSM[1]
#define goE &FSM[2]
#define waitE &FSM[3]
#define walk &FSM[4]
#define waitOn1 &FSM[5]
#define waitOff1 &FSM[6]
#define waitOn2 &FSM[7]
#define waitOff2 &FSM[8]
#define waitOn3 &FSM[9]
#define waitOff3 &FSM[10]
#define waitOn4 &FSM[11]
#define waitOff4 &FSM[12]
#define waitOn5 &FSM[13]
#define waitOff5 &FSM[14]
#define waitOn6 &FSM[15]

// Define a structure for the state
typedef const struct State STyp;

struct State
{
    uint32_t Out;                // Output value
    uint32_t Time;               // Time in 10 ms units
    const struct State *Next[16];  // Array of pointers to the next states
};

// Define an array of states to represent the finite state machine
STyp FSM[18] =
{
    // State 0: goN
    {0x61, 80, {goN, waitN, goN, waitN, waitN, waitN, waitN, waitN}},
    // State 1: waitN
    {0x4A, 40, {goE, goE, goE, goE, walk, walk, walk, walk}},
    // State 2: goE
    {0x4C, 80, {goE, goE, waitE, waitE, waitE, waitE, waitE, waitE}},
    // State 3: waitE
    {0x51, 40, {goN, goN, goN, goN, walk, walk, walk, walk}},
    // State 4: walk
    {0xA4, 40, {walk, waitOn1, waitOn1, waitOn1, walk, waitOn1, waitOn1, walk}},
    // State 5: waitOn1
    {0x24, 20, {waitOff1, waitOff1, waitOff1, waitOff1, waitOff1, waitOff1, waitOff1, waitOff1}},
    // State 6: waitOff1
    {0x64, 5, {waitOn2, waitOn2, waitOn2, waitOn2, waitOn2, waitOn2, waitOn2, waitOn2}},
    // State 7: waitOn2
    {0x24, 20, {waitOff2, waitOff2, waitOff2, waitOff2, waitOff2, waitOff2, waitOff2, waitOff2}},
    // State 8: waitOff2
    {0x64, 5, {waitOn3, waitOn3, waitOn3, waitOn3, waitOn3, waitOn3, waitOn3, waitOn3}},
    // State 9: waitOn3
    {0x24, 20, {waitOff3, waitOff3, waitOff3, waitOff3, waitOff3, waitOff3, waitOff3, waitOff3}},
    // State 10: waitOff3
    {0x64, 5, {waitOn4, waitOn4, waitOn4, waitOn4, waitOn4, waitOn4, waitOn4, waitOn4}},
    // State 11: waitOn4
    {0x24, 20, {waitOff4, waitOff4, waitOff4, waitOff4, waitOff4, waitOff4, waitOff4, waitOff4}},
    // State 12: waitOff4
    {0x64, 5, {waitOn5, waitOn5, waitOn5, waitOn5, waitOn5, waitOn5, waitOn5, waitOn5}},
    // State 13: waitOn5
    {0x24, 20, {waitOff5, waitOff5, waitOff5, waitOff5, waitOff5, waitOff5, waitOff5, waitOff5}},
    // State 14: waitOff5
    {0x64, 5, {waitOn6, waitOn6, waitOn6, waitOn6, waitOn6, waitOn6, waitOn6, waitOn6}},
    // State 15: waitOn6
    {0x24, 20, {goE, goE, goE, goE, goE, goE, goE, goE}}
};

#endif /* MAIN_H_ */
