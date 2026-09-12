INCLUDE Irvine32.inc

.data
itemA DWORD 45000
itemB DWORD 62000

.code
main PROC

mov EAX, itemA
mov EBX, itemB

add EAX, 30000
sub EBX, 70000

mov itemA, EAX ;the actual output is 000124F8
mov itemB, EBX

call DumpRegs
exit

main ENDP
END main
