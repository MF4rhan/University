INCLUDE Irvine32.inc

.data
msg1 BYTE "Length of Room: ", 0
msg2 BYTE "Width of Room: ", 0
msg3 BYTE "Area of Room: ", 0
msg4 BYTE "Total Area of Both Rooms: ", 0
total DWORD 0
saveAddress DWORD ?

.code
main PROC
mov ECX, 2
mov EAX, 0
mov EBX, 0
room:
call Crlf

mov EDX, OFFSET msg1
call WriteString
call ReadInt
mov EBX, EAX

mov EDX, OFFSET msg2
call WriteString
call ReadInt

push EAX
push EBX

call calculatePrice
add total, EAX
call Crlf
mov EDX, OFFSET msg3
call WriteString
call WriteDec

loop room

call Crlf
call Crlf
mov EDX, OFFSET msg4
call WriteString
mov EAX, total
call WriteDec

exit
main ENDP

calculatePrice PROC
pop saveAddress
pop EBX
pop EAX

mul EBX

push saveAddress
ret
calculatePrice ENDP

END main

