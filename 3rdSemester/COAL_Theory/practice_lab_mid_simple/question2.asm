INCLUDE Irvine32.inc

.data
tanks DWORD 500, 750, 300, 950
msg1 BYTE "Total Fuel = ", 0

.code
main PROC

mov ESI, OFFSET tanks
mov EAX, 0
add EAX, DWORD PTR [ESI]
add ESI, TYPE tanks
add EAX, DWORD PTR [ESI]
add ESI, TYPE tanks
add EAX, DWORD PTR [ESI]
add ESI, TYPE tanks
add EAX, DWORD PTR [ESI]
add ESI, TYPE tanks

mov EDX, OFFSET msg1
call WriteString

call WriteInt

exit
main ENDP
END main