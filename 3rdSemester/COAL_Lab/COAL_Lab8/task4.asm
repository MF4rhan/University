INCLUDE Irvine32.inc

.data
msg1 BYTE "Comparision EAX = 50 with 75: ", 0
msg2 BYTE "Comparision EAX = 75 with 75: ", 0
msg3 BYTE "Comparision EAX = 90 with 75: ", 0
msg4 BYTE "Comparision AL = -100 with 100: ", 0

.code
main PROC
XOR EAX, EAX
mov EAX, 50
cmp EAX, 75
mov EDX, OFFSET msg1
call WriteString
call Crlf
call DumpRegs

XOR EAX, EAX
mov EAX, 75
cmp EAX, 75
mov EDX, OFFSET msg2
call WriteString
call Crlf
call DumpRegs

XOR EAX, EAX
mov EAX, 90
cmp EAX, 75
mov EDX, OFFSET msg3
call WriteString
call Crlf
call DumpRegs

XOR EAX, EAX
mov AL, -100
cmp AL, 100
mov EDX, OFFSET msg4
call WriteString
call Crlf
call DumpRegs

exit
main ENDP
END main
