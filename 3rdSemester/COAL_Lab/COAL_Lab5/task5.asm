INCLUDE Irvine32.inc

.data
scanner DWORD 250, 899, 1500, 375
msg1 BYTE "Items Scanned = ",0
msg2 BYTE "Memory used (Bytes) = ",0
msg3 BYTE "Total Bill (Cents) = ", 0

.code
main PROC
mov edx, offset msg1
call writestring

mov esi, TYPE scanner
mov eax, esi
call WriteINT
call Crlf

mov eax, SIZEOF scanner
mov edx, offset msg2
call WriteString
call WriteInt
call Crlf

mov eax, [scanner]
add eax, [scanner + esi]
add esi, type scanner
add eax, [scanner + esi]
add esi, type scanner
add eax, [scanner + esi]

mov edx, offset msg3
call writeString
call WriteInt

exit
main ENDP
END main