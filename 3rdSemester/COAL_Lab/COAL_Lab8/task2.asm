INCLUDE Irvine32.inc

.data


.code
main PROC
XOR EAX, EAX
XOR EBX, EBX
XOR ECX, ECX
XOR EDX, EDX

mov Al, '8'
AND AL, 00001111b
mov BL, AL

OR AL, 00110000b

mov CL, 'g'
AND CL, 11011111b

mov DL, 'M'
OR Dl, 00100000b

call DumpRegs

exit
main ENDP
END main
