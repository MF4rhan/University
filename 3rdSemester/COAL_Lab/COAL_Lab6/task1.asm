INCLUDE Irvine32.inc

.data
array DWORD 5 DUP(?)
msg1 BYTE "Enter Quiz Score: ", 0
msg2 BYTE "The Total Sum is: ", 0
sum DWORD 0

.code
main PROC

mov ESI, 0
mov ECX, LENGTHOF array
L1:
mov EDX, OFFSET msg1
call WriteString
call ReadInt
add sum, EAX
mov array[ESI*TYPE array], EAX
inc ESI
call Crlf
loop L1

mov EAX, sum
mov EDX, OFFSET msg2
call WriteString
call WriteInt

exit
main ENDP
END main