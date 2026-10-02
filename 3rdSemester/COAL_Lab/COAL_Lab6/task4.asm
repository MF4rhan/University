INCLUDE Irvine32.inc

.data
msg1 BYTE "REPORT HEADER", 0
msg2 BYTE "FOOTER", 0
msg3 BYTE "DEBUG SECTION", 0

.code
main PROC

mov EDX, OFFSET msg1
call WriteString
call Crlf

JMP Jumper

mov EDX, OFFSET msg3
call WriteString
call Crlf

Jumper:
mov EDX, OFFSET msg2
call WriteString
call Crlf

exit
main ENDP
END main