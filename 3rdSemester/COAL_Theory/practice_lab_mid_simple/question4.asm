INCLUDE Irvine32.inc

.data
ID DWORD 002A0F13h
msg1 BYTE "Low Part (Hex) = ", 0
msg2 BYTE "High Part (Hex) = ", 0

.code
main PROC
mov EAX, 0
mov AX, WORD PTR ID
mov EDX, OFFSET msg1
call WriteString
call WriteHex

call Crlf

mov AX, WORD PTR [ID + 2]
mov EDX, OFFSET msg2
call WriteString
call WriteHex

exit
main ENDP
END main