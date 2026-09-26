INCLUDE Irvine32.inc

.data
products BYTE 100, 200, 150, 80, 60
arrSize BYTE LENGTHOF products
.code
main PROC

mov esi, 3
add products[esi], 25

movzx ecx, arrSize
mov esi, 0

L1:
movzx EAX, products[esi]
call WriteDec
mov EAX, ' '
call WriteChar
add ESI, TYPE products
Loop L1

call CRLF
call dumpregs

exit
main ENDP
END main