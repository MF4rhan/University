INCLUDE Irvine32.inc

.data
rain DWORD 45, 120, 75, 30

.code
main PROC
mov ESI, OFFSET rain

mov EAX, 0
mov ECX, LENGTHOF rain
L1:
add EAX, [ESI]
add ESI, TYPE DWORD
loop L1

call WriteDec

exit
main ENDP
END main