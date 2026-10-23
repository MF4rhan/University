INCLUDE Irvine32.inc

.data
msg1 BYTE "Grade: A", 0
msg2 BYTE "Grade: B", 0
msg3 BYTE "Grade: C", 0
msg4 BYTE "Grade: Fail", 0

.code
main PROC

xor EAX, EAX
call ReadInt

cmp EAX, 85
JAE Agrade
cmp EAX, 70
JAE Bgrade
cmp EAX, 50
JAE Cgrade
mov EDX, OFFSET msg4
call WriteString
jmp escaper

Agrade:
mov EDX, OFFSET msg1
call WriteString
jmp escaper

Bgrade:
mov EDX, OFFSET msg2
call WriteString
jmp escaper

Cgrade:
mov EDX, OFFSET msg3
call WriteString

escaper:

exit
main ENDP
END main
