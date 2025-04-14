### Subroutine to find a given character in a string and return
### its index.
### Fill in the rest of this file.

    #Expose the subroutine
    .global findChar

#Send to text section
    .text 

findChar:
    # iterate over the values of rdi until it matches esi or \0 is reached
    mov $0, %eax
start:


    movb (%rdi), %cl

    
    # cmp the array and char for equivalence
    cmp %cl, %sil
    je found

    # the null terminator was reached so there is no more to read
    cmp $0, %cx
    je notFound

    # a char is one byte so add 1
    add $1, %rdi
    inc %eax
    jmp start

found:
    ret
notFound:
    movl $-1, %eax
    ret
