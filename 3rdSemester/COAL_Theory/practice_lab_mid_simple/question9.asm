INCLUDE Irvine32.inc

.data
profit SDWORD 2400

.code
main PROC

mov EAX, 0
mov EBX, 0
mov EAX, profit
NEG profit
mov EBX, profit

call DumpRegs

exit
main ENDP
END main