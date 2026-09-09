INCLUDE Irvine32.inc

.data

.code
main PROC

mov EAX, 25h ;step 1
mov EBX, 100h ;step 2
add EAX, 25h ;step 3
mov EBX, EAX ;step 4
add EBX, 69h ;step 5

call DumpRegs

exit
main ENDP
END main
