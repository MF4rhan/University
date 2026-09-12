INCLUDE Irvine32.inc

.data

counting BYTE 3

.code
main PROC
INC counting ;first car arrived
INC counting ;second car arrived

DEC counting ;first car left
DEC counting ;second car left
DEC counting ;third car left

movzx eax, counting ;putting into register
call DumpRegs
exit

main ENDP
END main
