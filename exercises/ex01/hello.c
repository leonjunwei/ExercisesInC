#include <stdio.h>

int main() {
    int x = 5;
    int y = x + 1;
    printf("%i",y);
    return 0;
}


/*
The unoptimized assembly code for the "Hello, World" printer had a line "movl    $5, -4(%rbp)" that wasn't there before I added "int x = 5". This line disappeared in the optimized assembly code for the "Hello, World" printer, probably because we never use x.


When optimizing all files, the assembly code got shorter. I'm not sure what exactly happened. The references to %rbp and %rsp became much less frequent, and we see things like %eax and %edi instead. According to 15s on google, rbp and rsp have to do with the stack frame and eax and edi are accumulator registers of some sort.

Is the optimizer making some adjustments to where in memory the information should be stored? I don't know.


When we made y = x + 1, in the unoptimized code we see some stuff corresponding to the storage of x = 5, a calculation of 5+1 and then storing y = x+1 = 6. In the optimized code, we start right away with storing y = 6.

It looks like the optimizer is doing a little bit of pre-processing (probably with constants and such).

*/


/*
###########################
Unoptimized code to print "Hello, World"
###########################
    .file   "hello.c"
    .section    .rodata
.LC0:
    .string "Hello, World!"
    .text
    .globl  main
    .type   main, @function
main:
.LFB0:
    .cfi_startproc
    pushq   %rbp
    .cfi_def_cfa_offset 16
    .cfi_offset 6, -16
    movq    %rsp, %rbp
    .cfi_def_cfa_register 6
    subq    $16, %rsp
    movl    $5, -4(%rbp)
    movl    $.LC0, %edi
    call    puts
    movl    $0, %eax
    leave
    .cfi_def_cfa 7, 8
    ret
    .cfi_endproc
.LFE0:
    .size   main, .-main
    .ident  "GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.1) 4.8.4"
    .section    .note.GNU-stack,"",@progbits


My best guess for int x = 5 is: 

movl    $5, -4(%rbp)


######################################################
Optimized code of printing "Hello, World!":
######################################################
    .file   "hello.c"
    .section    .rodata.str1.1,"aMS",@progbits,1
.LC0:
    .string "Hello, World!"
    .section    .text.startup,"ax",@progbits
    .p2align 4,,15
    .globl  main
    .type   main, @function
main:
.LFB24:
    .cfi_startproc
    subq    $8, %rsp
    .cfi_def_cfa_offset 16
    movl    $.LC0, %edi
    call    puts
    xorl    %eax, %eax
    addq    $8, %rsp
    .cfi_def_cfa_offset 8
    ret
    .cfi_endproc
.LFE24:
    .size   main, .-main
    .ident  "GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.1) 4.8.4"
    .section    .note.GNU-stack,"",@progbits


****************************************
Unoptimized code for printing value of x:
****************************************
    .file   "hello.c"
    .section    .rodata
.LC0:
    .string "%i"
    .text
    .globl  main
    .type   main, @function
main:
.LFB0:
    .cfi_startproc
    pushq   %rbp
    .cfi_def_cfa_offset 16
    .cfi_offset 6, -16
    movq    %rsp, %rbp
    .cfi_def_cfa_register 6
    subq    $16, %rsp
    movl    $5, -4(%rbp)
    movl    -4(%rbp), %eax
    movl    %eax, %esi
    movl    $.LC0, %edi
    movl    $0, %eax
    call    printf
    movl    $0, %eax
    leave
    .cfi_def_cfa 7, 8
    ret
    .cfi_endproc
.LFE0:
    .size   main, .-main
    .ident  "GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.1) 4.8.4"
    .section    .note.GNU-stack,"",@progbits

******************************
Optimized code for printing x:
******************************
    .file   "hello.c"
    .section    .rodata.str1.1,"aMS",@progbits,1
.LC0:
    .string "%i"
    .section    .text.startup,"ax",@progbits
    .p2align 4,,15
    .globl  main
    .type   main, @function
main:
.LFB24:
    .cfi_startproc
    subq    $8, %rsp
    .cfi_def_cfa_offset 16
    movl    $5, %edx
    movl    $.LC0, %esi
    movl    $1, %edi
    xorl    %eax, %eax
    call    __printf_chk
    xorl    %eax, %eax
    addq    $8, %rsp
    .cfi_def_cfa_offset 8
    ret
    .cfi_endproc
.LFE24:
    .size   main, .-main
    .ident  "GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.1) 4.8.4"
    .section    .note.GNU-stack,"",@progbits

###########################
Unoptimized code to print y:
###########################
    .file   "hello.c"
    .section    .rodata
.LC0:
    .string "%i"
    .text
    .globl  main
    .type   main, @function
main:
.LFB0:
    .cfi_startproc
    pushq   %rbp
    .cfi_def_cfa_offset 16
    .cfi_offset 6, -16
    movq    %rsp, %rbp
    .cfi_def_cfa_register 6
    subq    $16, %rsp
    movl    $5, -8(%rbp)
    movl    -8(%rbp), %eax
    addl    $1, %eax
    movl    %eax, -4(%rbp)
    movl    -4(%rbp), %eax
    movl    %eax, %esi
    movl    $.LC0, %edi
    movl    $0, %eax
    call    printf
    movl    $0, %eax
    leave
    .cfi_def_cfa 7, 8
    ret
    .cfi_endproc
.LFE0:
    .size   main, .-main
    .ident  "GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.1) 4.8.4"
    .section    .note.GNU-stack,"",@progbits

###########################
Optimized code to print y:
###########################
    .file   "hello.c"
    .section    .rodata.str1.1,"aMS",@progbits,1
.LC0:
    .string "%i"
    .section    .text.startup,"ax",@progbits
    .p2align 4,,15
    .globl  main
    .type   main, @function
main:
.LFB24:
    .cfi_startproc
    subq    $8, %rsp
    .cfi_def_cfa_offset 16
    movl    $6, %edx
    movl    $.LC0, %esi
    movl    $1, %edi
    xorl    %eax, %eax
    call    __printf_chk
    xorl    %eax, %eax
    addq    $8, %rsp
    .cfi_def_cfa_offset 8
    ret
    .cfi_endproc
.LFE24:
    .size   main, .-main
    .ident  "GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.1) 4.8.4"
    .section    .note.GNU-stack,"",@progbits



*/
