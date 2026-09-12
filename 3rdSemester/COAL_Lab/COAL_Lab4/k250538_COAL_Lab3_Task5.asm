INCLUDE Irvine32.inc

.data

profit SDWORD 1500

.code
main PROC

mov eax, profit
mov ebx, eax

neg ebx

call DumpRegs
exit

main ENDP
END main
