INCLUDE Irvine32.inc

.data
number1 WORD 69
number2 WORD 67

.code
main PROC
mov eax, 0 ;clearing the registers for more clarity
mov ebx, 0 ;although this is optional

mov AX, number1
mov BX, number2
add AX, 12 ;adding 12 to AX

sub AX, BX ;subbing BX from AX, also the breakpoint is here

call DumpRegs
exit
main ENDP
END main
