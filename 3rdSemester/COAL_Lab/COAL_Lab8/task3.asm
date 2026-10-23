INCLUDE Irvine32.inc

.data
msg1 BYTE "Enter status Number (0 - 7): ", 0
msg2 BYTE "Paper Tray is Empty.", 0
msg3 BYTE "Jam Detected.",0
msg4 BYTE "Printer is Ready.", 0
.code
main PROC
mov EAX, 0
mov EDX, OFFSET msg1
call WriteString
call ReadInt
mov EBX, EAX
AND EBX, 00000110b
cmp EBX, 00000110b
JE combo
test EAX, 00000010b
JNZ empty
test EAX, 00000100b
JNZ jam

call Crlf
mov EDX, OFFSET msg4
call WriteString
jmp escaper

combo:
call Crlf
mov EDX, OFFSET msg2
call WriteString
call Crlf
mov EDX, OFFSET msg3
call WriteString
jmp escaper

empty:
call Crlf
mov EDX, OFFSET msg2
call WriteString
jmp escaper

jam:
call Crlf
mov EDX, OFFSET msg3
call WriteString

escaper:


exit
main ENDP 
END main
