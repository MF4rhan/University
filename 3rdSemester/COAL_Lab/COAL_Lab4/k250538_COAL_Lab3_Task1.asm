INCLUDE Irvine32.inc

.data

reading BYTE 0E8h

.code
main PROC

movzx eax, reading
movsx ebx, reading

call DumpRegs
exit

main ENDP
END main
