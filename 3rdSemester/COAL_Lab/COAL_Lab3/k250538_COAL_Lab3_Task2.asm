INCLUDE Irvine32.inc

.data
decimal_system BYTE 15
binary_system BYTE 1111b
octal_system BYTE 17o
hexa_system BYTE 0Fh

.code
main PROC

mov eax, 0 ;cleaning out the register so the end result is more obvious
mov ebx, 0
mov ecx, 0
mov edx, 0

mov al, decimal_system
mov bl, binary_system
mov cl, octal_system
mov dl, hexa_system

call dumpregs

exit
main ENDP
END main
