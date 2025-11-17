#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cradle.h"

void expression(void)
{
    if (is_addop_char(look)) {
        emit_ln("xor %eax, %eax");
    } else {
        
    }
}

int main(int argc, char *argv[])
{
    initialize();

    emit_ln(".text");
    emit_ln(".global _start");
    emit_ln("_start:");
    
    // Expression evaluation
    expression();

    // Finally, return the result
    emit_ln("movl %eax, %ebx");
    emit_ln("movl $1, %eax");
    emit_ln("int $0x80");

    return 0;
}