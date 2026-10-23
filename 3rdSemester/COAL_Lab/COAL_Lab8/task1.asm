INCLUDE Irvine32.inc

.data
daystart BYTE 10010110b

.code
main PROC
mov EAX, 0
mov EBX, 0

mov AL, daystart

OR AL, 00001001b
AND AL, 01101111b

XOR AL, 00000110b
mov BL, AL
XOR BL, 11111111b

call DumpRegs

exit
main ENDP
END main
