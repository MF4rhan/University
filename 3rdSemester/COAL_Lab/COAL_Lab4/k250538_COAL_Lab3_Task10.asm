INCLUDE irvine32.inc

.data

.code
main PROC
mov EAX, 12345678h
mov AX, 0


call DumpRegs

exit
main ENDP
END main
