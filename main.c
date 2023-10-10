#include "main.h"

// Function to initialize GPIO pins
void GpioInit()
{
    // Output Button 1
    P4SEL1 &= ~0x0F;
    P4SEL0 &= ~0x3F;
    P4DIR |= 0x3F;

    // Input Button 2
    P5SEL1 &= ~0x07;
    P5SEL0 &= ~0x07;
    P5DIR &= 0x07;

    // Part 2
    // Input Button 3
    P2SEL1 &= ~0x03;
    P2SEL0 &= ~0x03;
    P2DIR |= 0x03;
}

void main()
{
    STyp *ptr;  // State pointer
    GpioInit(); // Initialize GPIO pins
    uint32_t Input;
    SysTick_Init(); // Initialize SysTick timer
    ptr = goN;      // Start state

    while (1)
    {
        // Set lights output on P4
        P4OUT = (ptr->Out & 0xFF) & 0x3F;
        // Set lights output on P2
        P2OUT = ((ptr->Out & 0xFF) & 0xC0) >> 6;

        // Wait for a specific time determined by the current state
        SysTick_Wait10ms(ptr->Time);

        // Read sensor input from P5
        Input = (P5IN & 0x07);

        // Transition to the next state based on sensor input
        ptr = ptr->Next[Input];
    }
}
