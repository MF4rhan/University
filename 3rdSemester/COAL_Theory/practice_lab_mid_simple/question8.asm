INCLUDE Irvine32.inc

.data
riderA WORD 25
riderB WORD 40

.code
main PROC
mov EAX, 0

mov AX, riderA
XCHG AX, riderB
mov riderA, AX


mov EBX, 0
mov BX, riderB
call DumpRegs


exit
main ENDP
END main