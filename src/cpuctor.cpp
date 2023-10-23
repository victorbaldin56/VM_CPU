#include "stack.h"
#include "VM.h"

CPU *CPU_Ctor(CPU *cpu) {
    assert(cpu);

    StackCtor(&cpu->stack);

    return cpu;
}

void CPU_Dtor(CPU *cpu) {
    assert(cpu);

    StackDtor(&cpu->stack);
}
