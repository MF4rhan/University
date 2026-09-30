INCLUDE Irvine32.inc

.data
trays DWORD 12, 8, 15, 20, 5, 9
msg1 BYTE " ", 0
msg2 BYTE "Updated Trays: ", 0

.code
main PROC

mov ESI, 2
sub trays[ESI * TYPE trays], 4

mov ESI, 0;
mov EDX, OFFSET msg2
call WriteString
mov EAX, trays[ESI * TYPE trays]
call WriteInt
mov EDX, OFFSET msg1
call WriteString
mov ESI, 1
mov EAX, trays[ESI * TYPE trays]
call WriteInt
mov EDX, OFFSET msg1
call WriteString
mov ESI, 2
mov EAX, trays[ESI * TYPE trays]
call WriteInt
mov EDX, OFFSET msg1
call WriteString
mov ESI, 3
mov EAX, trays[ESI * TYPE trays]
call WriteInt
mov EDX, OFFSET msg1
call WriteString
mov ESI, 4
mov EAX, trays[ESI * TYPE trays]
call WriteInt
mov EDX, OFFSET msg1
call WriteString
mov ESI, 5

exit
main ENDP
END main