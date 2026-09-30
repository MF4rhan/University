INCLUDE Irvine32.inc

TARGET EQU 5
.data
ticket DWORD 200, 350, 400, 150, 600, 450, 500
msg1 BYTE "Price of Class 5 = ", 0

.code
main PROC
mov EAX, 0
mov EAX, ticket[TARGET * TYPE ticket]
mov EDX, OFFSET msg1
call WriteString
call WriteInt

exit
main ENDP
END main