INCLUDE Irvine32.inc

.data
items DWORD 250, 899, 1500, 375
num BYTE "Number of Items Scanned: ", 0
Memsize BYTE "Total Memory used: ", 0
total BYTE "Total Bill is: ", 0

.code
main PROC
mov ESI, 0
mov ECX, LENGTHOF items

mov EDX, OFFSET num
call WriteString
mov EAX, ECX
call WriteDec

call Crlf

mov EDX, OFFSET Memsize
call WriteString
mov EAX, SIZEOF items
call WriteDec

call Crlf


mov EAX, 0
L1:
add EAX, items[ESI]
add ESI, TYPE items
loop L1

mov EDX, OFFSET total
call WriteString
call WriteDec

exit
main ENDP
END main