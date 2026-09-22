INCLUDE Irvine32.inc

.data
warehouse BYTE 100, 200, 150, 80, 60

msg BYTE "Updated Stock: ", 0
msg1 BYTE " ", 0

.code
main PROC
mov esi, OFFSET warehouse
add BYTE PTR [esi+3], 25

mov edx, OFFSET msg
call WriteString

movzx EAX, BYTE PTR [esi]
call WriteInt

mov EDX, OFFSET msg1
call WriteString
add esi, TYPE warehouse
movzx EAX, BYTE PTR [esi]
call WriteInt

mov EDX, OFFSET msg1
call WriteString
add esi, TYPE warehouse
movzx EAX, BYTE PTR [esi]
call WriteInt

mov EDX, OFFSET msg1
call WriteString
add esi, TYPE warehouse
movzx EAX, BYTE PTR [esi]
call WriteInt

mov EDX, OFFSET msg1
call WriteString
add esi, TYPE warehouse
movzx EAX, BYTE PTR [esi]
call WriteInt

exit
main ENDP
END main