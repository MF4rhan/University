INCLUDE Irvine32.inc

.data
students WORD 78, 85, 90, 66, 72
msg1 BYTE "Students = ", 0
msg2 BYTE "Memory Used (Bytes) = ", 0
msg3 BYTE "Total Marks = ", 0

.code
main PROC

mov EAX, LENGTHOF students
mov EDX, OFFSET msg1
call WriteString
call WriteInt
call Crlf

mov EAX, SIZEOF students
mov EDX, OFFSET msg2
call WriteString
call WriteInt
call Crlf

mov EAX, 0
mov ESI, 0
mov ECX, LENGTHOF students

L1:
add AX, students[ESI*TYPE students]
inc ESI
loop L1

mov EDX, OFFSET msg3
call WriteString
call WriteInt
call Crlf

exit
main ENDP
END main