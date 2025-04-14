### Subroutines called from C.
    
### You should be able to compile this with each of the
### test programs to try out each of the functions.
    
    ## Expose the names of all of our subroutines.
    .global setGlobal
    .global swapGlobals
    .global sixParams
    .global formula
    ## Code goes in the text section.
    .text

### Implementation of setGlobal, assign 47 to a global variable.
setGlobal:
    
    movl $47, globalVar         # an int is 4 bytes so a longword is needed
    ret                         # Return to the caller.
    
### Implementation of swapGlobals, exchange the value of two global variables
swapGlobals:
    mov globalA, %eax
    mov globalB, %ecx  # store variables in the registers and swap
    mov %eax, globalB
    mov %ecx, globalA
    ret

### Implementation of a six parameter functions
sixParams:
    
    push %rbp 
    mov %rsp, %rbp

    push %r12
    push %r13
    
   

    # the 6 parameters come in the registers in this order
    # rdi, rsi, rdx, rcx, r8, r9
    mov %edi, %r11d
    # multipled a * d
    imul %ecx, %r11d

    mov %esi, %r12d   
    # multiplied b * e
    imul %r8d, %r12d

    mov %edx, %r13d
    # multiplied c * f
    imul %r9d, %r13d


    # add the first two vals then subtract
    add %r11d, %r12d

    sub %r13d, %r12d

    mov %r12d, %eax

    pop %r13
    pop %r12
    pop %rbp

    ret


### implementation of parameters, immediates, and globals
formula:
    # x * ( 100 - globalA * y ) + 3 * globalB * globalB
    # store 100 and 3 in some processors
    
    push %rbp
    mov %rsp, %rbp

    push %r12
    push %r15

    # read in rdi and rsi from params
    mov %edi, %r11d
    mov %esi, %r12d 
    
    # read in all the global variables
    # mov globalA, %r13d
    # mov globalB, %r14d

    # ( 100 - globalA * y )
    imul globalA, %r12d
    mov $100, %r15d
    sub %r12d, %r15d
    mov %r15d, %r12d    

    # x * ( 100 - globalA * y )
    imul %r12d, %r11d
    
    # 3 + globalB * globalB
    mov globalB, %eax
    imul globalB, %eax
    imul $3, %eax

    add %r11d, %eax

    pop %r15
    pop %r12
    pop %rbp
    ret






