Include Irvine32.inc

.data
shop DWORD 1200, 1500, 900, 1750, 2000

msg1 BYTE "Total Sales = ", 0
.code
main PROC

mov eax, 0
mov esi, offset shop

add eax, [esi]
add esi, type shop

add eax, [esi]
add esi, type shop

add eax, [esi]
add esi, type shop

add eax, [esi]
add esi, type shop

add eax, [esi]

mov edx, offset msg1
call writestring

call writeInt
call Crlf

exit
main ENDP
END main